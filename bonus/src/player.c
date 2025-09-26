/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:01:08 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:04:56 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	calculate_next_step(t_game *game, int move_step, int side_move)
{
	double	to_x;
	double	to_y;
	double	angle;
	int		margin_x;
	int		margin_y;

	angle = game->player.xy.angle;
	to_x = (cos(angle) * move_step) + (cos(angle + HALF_PI) * side_move);
	to_y = (sin(angle) * move_step) + (sin(angle + HALF_PI) * side_move);
	margin_x = 16;
	margin_y = 16;
	if (to_x < 0)
		margin_x = -16;
	if (to_y < 0)
		margin_y = -16;
	to_x += game->player.xy.x;
	to_y += game->player.xy.y;
	if (!has_blocking_tile(game, to_x + margin_x, to_y + margin_y) && \
		!collide_diagonal(game, to_x + margin_x, to_y + margin_y))
	{
		game->player.xy.x = to_x;
		game->player.xy.y = to_y;
	}
}

void	bound_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

void	player_movement(t_game *game)
{
	int		move;
	int		side;

	if (game->player.move_direction)
	{
		game->player.xy.angle += game->player.move_direction * game->player.rotate_speed;
		bound_angle(&game->player.xy.angle);
	}
	if (game->player.side_direction || game->player.walk_direction)
	{
		move = game->player.walk_direction * game->player.move_speed;
		side = game->player.side_direction * game->player.move_speed;
		if (game->player.side_direction && game->player.walk_direction)
		{
			move /= 2;
			side /= 2;
		}
		calculate_next_step(game, move, side);
	}
}




