#include "../inc/cub3D.h"

static void load_door_anim(t_game *game, t_door *door)
{
	int frames;

	frames = 4;
	door->anim.frames = malloc(sizeof(t_image) * frames);
	if (!door->anim.frames) error("Door frames alloc failed", game);
	door->anim.frame_count = frames;
	door->anim.current = 0;
	door->anim.timer = 0.0;
	if (set_sprite(&door->anim.frames[0], game->mlx, "./assets/door_close.XPM") ||
			set_sprite(&door->anim.frames[1], game->mlx, "./assets/door_open1.XPM") ||
			set_sprite(&door->anim.frames[2], game->mlx, "./assets/door_open2.XPM") ||
			set_sprite(&door->anim.frames[3], game->mlx, "./assets/door_openfull.XPM") )
		error("Could not load door frames", game);
}

void	register_doors(t_game *game)
{
	int	x;
	int	y;
	int	count;
	int	idx;

	count = 0;
	idx = 0;
	y = 0;
	while (game->params.map[y]) {
		x = 0;
		while (game->params.map[y][x]) {
			if (game->params.map[y][x] == DOOR_TILE)
				count++;
			x++;
		}
		y++;
	}
    game->door_count = count;
    if (count == 0)
	{
		game->doors = NULL;
		return;
	}
    game->doors = malloc(sizeof(t_door) * count);
    if (!game->doors)
		error("Door array allocation failed", game);
	y = 0;
	while (game->params.map[y])
	{
		x = 0;
		while (game->params.map[y][x])
		{
			if (game->params.map[y][x] == DOOR_TILE)
			{
				t_door *d = &game->doors[idx++];
				d->x = x;
				d->y = y;
				d->state = DOOR_MIN;
				d->opening = 0;
				load_door_anim(game, d);
			}
			x++;
		}
		y++;
	}
}

void	update_doors(t_game *game)
{
	int		i;
	t_door	*d;
	int		idx;

	i = 0;
	while (i < game->door_count)
	{
		d = &game->doors[i];
		if (d->opening == 1 && d->state < DOOR_MAX)
			d->state += DOOR_SPEED;
		else if (d->opening == -1 && d->state > DOOR_MIN)
			d->state -= DOOR_SPEED;
		if (d->state >= DOOR_MAX)
		{
			d->state = DOOR_MAX;
			d->opening = 0;
		}
		if (d->state <= DOOR_MIN)
		{
			d->state = DOOR_MIN;
			d->opening = 0;
		}
		idx = (int)(d->state * (d->anim.frame_count - 1) + 0.5);
		if (idx < 0)
			idx = 0;
		if (idx >= d->anim.frame_count)
			idx = d->anim.frame_count - 1;
		d->anim.current = idx;
		i++;
	}
}

int	clampi(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

t_camera	make_camera(const t_game *game)
{
	t_camera	c;
	double a;
	double pa;

	a = game->player.xy.angle;
	pa = a + HALF_PI;
	c.dirX = cos(a);
	c.dirY = sin(a);
	c.planeX = cos(pa) * (FOV_ANGLE);
	c.planeY = sin(pa) * (FOV_ANGLE);
	return (c);
}

t_vec2d	sprite_delta(const t_game *game, double sx, double sy)
{
	t_vec2d	d;

	d.x = sx - game->player.xy.x;
	d.y = sy - game->player.xy.y;
	return (d);
}

double	inv_det(const t_camera *c)
{
	double	det;

	det = (c->planeX * c->dirY) - (c->dirX * c->planeY);
	if (fabs(det) < 1e-9)
		return (1e9);
	return (1.0 / det);
}

t_vec2d	camera_space(const t_vec2d *d, const t_camera *c, double invDet)
{
	t_vec2d	t;

	t.x = invDet * ( c->dirY  * d->x - c->dirX  * d->y);
	t.y = invDet * (-c->planeY * d->x + c->planeX * d->y);
	return (t);
}

t_spriteproj	project_sprite(const t_game *game,
	const t_vec2d *t, t_image img)
{
	t_spriteproj	p;
	double			invY;
	int				baseH;

	invY = 1.0 / t->y;
	baseH = (int)(TILE_SIZE * invY * game->wall_prop.projected_wall);
	p.screenX = (int)(game->half_width * (1.0 + (t->x * invY)));
	p.height  = baseH;
	if (p.height < 1)
		p.height = 1;
	p.width = (int)((double)p.height * img.img->width / img.img->height);
	if (p.width < 1)
		p.width = 1;
	return (p);
}

t_drawrect	draw_rect(const t_game *game, const t_spriteproj *p)
{
	t_drawrect	r;
	int			hh;

	hh = game->half_height;
	r.startY = clampi(-p->height / 2 + hh, 0, game->window_height - 1);
	r.endY = clampi( p->height / 2 + hh, 0, game->window_height - 1);
	r.startX = clampi(-p->width / 2 + p->screenX, 0, game->window_width - 1);
	r.endX = clampi( p->width / 2 + p->screenX, 0, game->window_width - 1);
	return (r);
}

int	tex_x_for_stripe(int stripe, const t_spriteproj *p, int texW)
{
	int	left;
	int	texX;

	left = -p->width / 2 + p->screenX;
	texX = (int)((stripe - left) * (double)texW / (double)p->width);
	return (clampi(texX, 0, texW - 1));
}

int	tex_y_for_y(int y, const t_game *game, const t_spriteproj *p, int texH)
{
	int top;
	int d;
	int texY;

	top = -p->height / 2 + game->half_height;
	d = y - top;
	texY = (int)((double)d * (double)texH / (double)p->height);
	return (clampi(texY, 0, texH - 1));
}

void	draw_sprite_columns(t_game *game, t_image img,
    const t_spriteproj *p, const t_drawrect *r, double depth)
{
	int	stripe;
	int	texX;
	int	y;
	int	texY;
	uint32_t color;

	stripe = r->startX;
	while (stripe <= r->endX)
	{
		if (stripe >= 0 && stripe < game->window_width)
		{
			if (depth < game->zbuffer[stripe])
			{
				texX = tex_x_for_stripe(stripe, p, img.img->width);
				y = r->startY;
				while (y <= r->endY)
				{
					texY = tex_y_for_y(y, game, p, img.img->height);
					color = get_color(img, texX, texY);
					if ((color & 0xFF000000) != TRANSPARENCY)
						draw_px(game->img, stripe, y, color);
					y++;
				}
			}
		}
		stripe++;
	}
}

/* 10) Public entry: simple billboard sprite draw using zbuffer occlusion */
static void	draw_door_sprite(t_game *game, t_image img, double sx, double sy)
{
	t_camera cam   = make_camera(game);
	t_vec2d  delta = sprite_delta(game, sx, sy);
	double   inv   = inv_det(&cam);
	t_vec2d  t     = camera_space(&delta, &cam, inv);

	if (t.y <= 0.0001) return; // behind camera / degenerate

	t_spriteproj proj = project_sprite(game, &t, img);
	t_drawrect   rect = draw_rect(game, &proj);

	draw_sprite_columns(game, img, &proj, &rect, t.y);
}

// 11) Public: draw all doors as sprites (call this after draw_walls)
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
