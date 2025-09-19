#include "cub3D.h"

int mouse_move(int x, int y, t_game *game)
{
    int center_x = game->window_width / 2;
    int delta_x = x - center_x;

    (void)y;

    if (delta_x != 0)
    {
        double sensitivity = 0.002;
        game->player.xy.angle += delta_x * sensitivity;
        bound_angle(&game->player.xy.angle);
        mlx_mouse_move(game->mlx, game->window, center_x, game->window_height / 2);
    }
    return (0);
}