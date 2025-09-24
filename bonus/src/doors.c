#include "../inc/cub3D.h"

static void load_door_anim(t_game *game, t_door *door)
{
    const int frames = 4; // closed, opening1, opening2, open
    door->anim.frames = malloc(sizeof(t_image) * frames);
    if (!door->anim.frames) error("Door frames alloc failed", game);
    door->anim.frame_count = frames;
    door->anim.current = 0;
    door->anim.timer = 0.0;

    // Replace these with your actual files:
    if ( set_sprite(&door->anim.frames[0], game->mlx, "./assets/door_closed.xpm") ||
         set_sprite(&door->anim.frames[1], game->mlx, "./assets/door_opening1.xpm") ||
         set_sprite(&door->anim.frames[2], game->mlx, "./assets/door_opening2.xpm") ||
         set_sprite(&door->anim.frames[3], game->mlx, "./assets/door_open.xpm") )
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
