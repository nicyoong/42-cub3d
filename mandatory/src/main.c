/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:49:21 by tching            #+#    #+#             */
/*   Updated: 2025/08/20 20:49:33 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int argc, char **argv)
{
    t_game  game;

    init_cubed(&game);
    open_file(&game, argc, argv[argc - 1]);
    set_params(&game);
    validate_file(&game);
    setup_game(&game);
    start_cubed(&game);
    return (0);
}
void    init_cubed(t_game *game)
{
    ft_bzero(game, sizeof(t_game));
    ft_bzero(&game->player, sizeof(t_player));
    ft_bzero(&game->params, sizeof(t_params));
    game->window_width = WINDOW_WIDTH;
    game->window_height = WINDOW_HEIGHT;
    game->half_width = WINDOW_WIDTH / 2;
    game->half_height = WINDOW_HEIGHT / 2;
    game->wall_prop.projected_wall = game->half_width / tan(FOV_ANGLE 2 );
    game->params.texture = ft_calloc(sizeof(Char *), 4);
    game->player.rotate_speed = ROTATE_SPEED_2;
    game->player.move_speed = 4;
    if (!game->params.texture)
        error("Calloc failed", game);
}

int     init_graphics(t_game *game)
{
    player_movement(game);
    cast_all_rays(game);
    draw_cf(game);
    draw_walls(game);
    mlx_do_sync(game->mlx);
    mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
    return (0);
}

void    start_cubed(t_game *game)
{
    mlx_hook(game->window, 2, 1, press_key, game);
    mlx_hook(game->window, 3, 2, release_key, game);
    mlx_hook(game->window, 17, 0, close_window, game);
    mlx_loop_hook(game->mlx, init_graphics, game);
    mlx_loop(game->mlx);
}

void    error(char *message, t_game *game)
{
    printf("Error\n%s.\n%s\n", message, strerror(errno));
    free_matrix((void **)game->params.map, 0);
    free_matrix((void **)game->params.texture, 4);
    free_matrix((void **)game->params.color[0], 0);
    free_matrix((void **)game->params.color[1], 0);
    cleanup_game(game);
    free_game(game);
    exit(errno);
}