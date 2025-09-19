#include "cub3D.h"

int mouse_move(int x, int y, t_game *game)
{
    static int last_x = -1;

    (void)y;

    if (last_x == -1)
        last_x = x;

    int delta_x = x - last_x;
    last_x = x;

    double sensitivity = 0.002;

    game->player.xy.angle += delta_x * sensitivity;
    bound_angle(&game->player.xy.angle);

    return (0);
}