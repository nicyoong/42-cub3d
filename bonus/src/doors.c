#include "../inc/cub3D.h"

static void load_door_anim(t_game *game, t_door *door)
{
    const int frames = 4;
    door->anim.frames = malloc(sizeof(t_image) * frames);
    if (!door->anim.frames) error("Door frames alloc failed", game);
    door->anim.frame_count = frames;
    door->anim.current = 0;
    door->anim.timer = 0.0;

    // Replace these with your actual files:
    if ( set_sprite(&door->anim.frames[0], game->mlx, "./assets/doorwall.xpm") ||
         set_sprite(&door->anim.frames[1], game->mlx, "./assets/doorwall.xpm") ||
         set_sprite(&door->anim.frames[2], game->mlx, "./assets/doorwall.xpm") ||
         set_sprite(&door->anim.frames[3], game->mlx, "./assets/bark01.XPM") )
        error("Could not load door frames", game);
}

void register_doors(t_game *game)
{
    int x, y, count = 0, idx = 0;

    // 1) count
    for (y = 0; game->params.map[y]; y++)
        for (x = 0; game->params.map[y][x]; x++)
            if (game->params.map[y][x] == DOOR_TILE)
                count++;

    game->door_count = count;
    if (count == 0) { game->doors = NULL; return; }

    // 2) allocate array
    game->doors = malloc(sizeof(t_door) * count);
    if (!game->doors) error("Door array allocation failed", game);

    // 3) fill + load frames
    for (y = 0; game->params.map[y]; y++) {
        for (x = 0; game->params.map[y][x]; x++) {
            if (game->params.map[y][x] == DOOR_TILE) {
                t_door *d = &game->doors[idx++];
                d->x = x;
                d->y = y;
                d->state = DOOR_MIN;  // closed
                d->opening = 0;
                load_door_anim(game, d);
            }
        }
    }
}

void update_doors(t_game *game)
{
    for (int i = 0; i < game->door_count; i++) {
        t_door *d = &game->doors[i];

        if (d->opening == 1 && d->state < DOOR_MAX)       d->state += DOOR_SPEED;
        else if (d->opening == -1 && d->state > DOOR_MIN)  d->state -= DOOR_SPEED;

        if (d->state >= DOOR_MAX) { d->state = DOOR_MAX; d->opening = 0; }
        if (d->state <= DOOR_MIN) { d->state = DOOR_MIN; d->opening = 0; }

        // map state [0,1] to frame index 0..(n-1)
        int idx = (int)(d->state * (d->anim.frame_count - 1) + 0.5);
        if (idx < 0) idx = 0;
        if (idx >= d->anim.frame_count) idx = d->anim.frame_count - 1;
        d->anim.current = idx;
    }
}

// Simple billboard sprite draw using zbuffer occlusion
static void draw_door_sprite(t_game *game, t_image img, double sx, double sy)
{
	// Player orientation
	double dirX = cos(game->player.xy.angle);
	double dirY = sin(game->player.xy.angle);
	double planeX =  cos(game->player.xy.angle + HALF_PI) * (FOV_ANGLE);
	double planeY =  sin(game->player.xy.angle + HALF_PI) * (FOV_ANGLE);

	// Translate sprite to camera space
	double dx = sx - game->player.xy.x;
	double dy = sy - game->player.xy.y;

	// Inverse determinant for camera transform
	double invDet = 1.0 / (planeX * dirY - dirX * planeY);

	// Transform to camera space
	double transformX = invDet * ( dirY * dx - dirX * dy);
	double transformY = invDet * (-planeY * dx + planeX * dy);

	if (transformY <= 0.0001) return; // behind camera

	// Project to screen
	int spriteScreenX = (int)(game->half_width * (1 + transformX / transformY));
	int spriteHeight  = (int)fabs(game->wall_prop.projected_wall / transformY);
	int spriteWidth   = spriteHeight;

	int drawStartY = -spriteHeight / 2 + game->half_height;
	if (drawStartY < 0) drawStartY = 0;
	int drawEndY   =  spriteHeight / 2 + game->half_height;
	if (drawEndY >= game->window_height) drawEndY = game->window_height - 1;

	int drawStartX = -spriteWidth / 2 + spriteScreenX;
	if (drawStartX < 0) drawStartX = 0;
	int drawEndX   =  spriteWidth / 2 + spriteScreenX;
	if (drawEndX >= game->window_width) drawEndX = game->window_width - 1;

	// Draw with depth test
	for (int stripe = drawStartX; stripe <= drawEndX; stripe++) {
		int texX = (int)((stripe - (-spriteWidth/2 + spriteScreenX)) * img.img->width / (double)spriteWidth);

		// Occlusion: only draw if in front of wall at this column
		if (stripe >= 0 && stripe < game->window_width && transformY < game->zbuffer[stripe]) {
			for (int y = drawStartY; y <= drawEndY; y++) {
				int d = (y - (-spriteHeight/2 + game->half_height));
				int texY = (int)(d * img.img->height / (double)spriteHeight);
				uint32_t color = get_color(img, texX, texY);

				// Optional transparency check (depends on your XPMs)
				if ((color & 0xFF000000) != TRANSPARENCY)
					draw_px(game->img, stripe, y, color);
			}
		}
	}
}

// Public: draw all doors as sprites (call this after draw_walls)
void draw_doors_as_sprites(t_game *game)
{
	for (int i = 0; i < game->door_count; i++) {
		t_door *d = &game->doors[i];
		t_image frame = d->anim.frames[d->anim.current];

		// Center of door tile in world coords
		double world_x = (d->x + 0.5) * TILE_SIZE;
		double world_y = (d->y + 0.5) * TILE_SIZE;

		draw_door_sprite(game, frame, world_x, world_y);
	}
}

t_door *find_door(t_game *game, int map_x, int map_y)
{
    for (int i = 0; i < game->door_count; i++)
        if (game->doors[i].x == map_x && game->doors[i].y == map_y)
            return &game->doors[i];
    return NULL;
}

void toggle_door(t_game *game)
{
    double px = game->player.xy.x / TILE_SIZE;
    double py = game->player.xy.y / TILE_SIZE;

    int front_x = (int)(px + cos(game->player.xy.angle) * DOOR_INTERACT_DIST);
    int front_y = (int)(py + sin(game->player.xy.angle) * DOOR_INTERACT_DIST);

    if (front_x < 0 || front_y < 0 ||
        front_y >= (int)count_vectors((void**)game->params.map) ||
        front_x >= (int)ft_strlen(game->params.map[front_y]))
        return;

    if (game->params.map[front_y][front_x] == DOOR_TILE) {
        t_door *door = find_door(game, front_x, front_y);
        if (!door) return;
        if (door->state <= DOOR_MIN) door->opening = 1;   // start opening
        else if (door->state >= DOOR_MAX) door->opening = -1; // start closing
    }
}
