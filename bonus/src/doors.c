#include "../inc/cub3D.h"

void register_doors(t_game *game)
{
    int x, y;

    int count = 0;
    for (y = 0; game->params.map[y]; y++)
        for (x = 0; game->params.map[y][x]; x++)
            if (game->params.map[y][x] == DOOR_TILE)
                count++;
    if (count == 0)
    {
        game->doors = NULL;
        game->door_count = 0;
        return;
    }
    game->doors = malloc(sizeof(t_door) * count);
    if (!game->doors)
        error("Door array allocation failed", game);
    int idx = 0;
    for (y = 0; game->params.map[y]; y++)
    {
        for (x = 0; game->params.map[y][x]; x++)
        {
            if (game->params.map[y][x] == DOOR_TILE)
            {
                game->doors[idx].x = x;
                game->doors[idx].y = y;
                game->doors[idx].state = DOOR_MIN;
                game->doors[idx].opening = 0;
                idx++;
            }
        }
    }
    game->door_count = count;
}


void update_doors(t_game *game)
{
    for (int i = 0; i < game->door_count; i++)
    {
        t_door *door = &game->doors[i];

        if (door->opening == 1 && door->state < DOOR_MAX)
            door->state += DOOR_SPEED;
        else if (door->opening == -1 && door->state > DOOR_MIN)
            door->state -= DOOR_SPEED;
        if (door->state >= DOOR_MAX)
        {
            door->state = DOOR_MAX;
            door->opening = 0;
        }
        if (door->state <= DOOR_MIN)
        {
            door->state = DOOR_MIN;
            door->opening = 0;
        }
    }
}

void toggle_door(t_game *game)
{
    double px = game->player.xy.x / TILE_SIZE;
    double py = game->player.xy.y / TILE_SIZE;

    // check one step ahead in facing direction
    int front_x = (int)(px + cos(game->player.xy.angle) * DOOR_INTERACT_DIST);
    int front_y = (int)(py + sin(game->player.xy.angle) * DOOR_INTERACT_DIST);

    if (front_x < 0 || front_y < 0 ||
        front_y >= (int)count_vectors((void**)game->params.map) ||
        front_x >= (int)ft_strlen(game->params.map[front_y]))
        return;

    if (game->params.map[front_y][front_x] == DOOR_TILE)
    {
        t_door *door = find_door(game, front_x, front_y);
        if (!door) return;

        if (door->state <= DOOR_MIN)
            door->opening = 1; // start opening
        else if (door->state >= DOOR_MAX)
            door->opening = -1; // start closing
    }
}
