#include "../inc/cub3D.h"

void register_doors(t_game *game)
{
    int x, y;

    for (y = 0; game->params.map[y]; y++)
    {
        for (x = 0; game->params.map[y][x]; x++)
        {
            if (game->params.map[y][x] == DOOR_TILE)
            {
                t_door *door = malloc(sizeof(t_door));
                if (!door)
                    error("Door allocation failed", game);
                door->x = x;
                door->y = y;
                door->state = DOOR_MIN;
                door->opening = 0;
            }
        }
    }
}