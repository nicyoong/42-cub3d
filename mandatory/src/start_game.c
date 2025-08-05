/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:36:44 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 22:12:36 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_display(t_game *game)
{
	//placeholders
	//
	//
	mlx_do_sync(game->mlx);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}

void	start_cubed(t_game *game)
{
	mlx_hook(game->window, 2, 1, key_press_game, game);
	mlx_hook(game->window, 3, 2, key_release, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_loop_hook(game->mlx, display_game, game);
	mlx_loop(game->mlx);
}
