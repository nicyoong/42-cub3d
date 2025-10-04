/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:00:12 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:42:32 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_game *game)
{
	int		center_x;
	int		delta_x;
	double	sensitivity;

	center_x = game->window_width / 2;
	delta_x = x - center_x;
	(void)y;
	if (delta_x != 0)
	{
		sensitivity = 0.001;
		game->player.xy.angle += delta_x * sensitivity;
		bound_angle(&game->player.xy.angle);
		mlx_mouse_move(game->mlx, game->window,
			center_x, game->window_height / 2);
	}
	return (0);
}
