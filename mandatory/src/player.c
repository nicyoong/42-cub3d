/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:15:04 by tching            #+#    #+#             */
/*   Updated: 2025/09/26 22:35:42 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	has_wall(t_game *game, double x, double y)
{
	int	column;
	int	line;

	column = (int)floor((x / TILE_SIZE));
	line = (int)floor((y / TILE_SIZE));
	if (y < 0 || y > game->minimap_height || x < 0
		|| x > ft_strlen(game->params.map[line]) * TILE_SIZE)
		return (1);
	return (game->params.map[line][column] == '1');
}

int	collide_diagonal(t_game *game, double to_x, double to_y)
{
	double		x_diff;
	double		y_diff;

	x_diff = to_x - game->player.xy.x;
	y_diff = to_y - game->player.xy.y;
	if (fabs(x_diff) <= TILE_SIZE && fabs(y_diff) <= TILE_SIZE)
	{
		if (has_wall(game, to_x - x_diff, to_y))
			return (1);
		if (has_wall(game, to_x, to_y - y_diff))
			return (1);
	}
	return (0);
}

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
	if (!has_wall(game, to_x + margin_x, to_y + margin_y)
		&& !collide_diagonal(game, to_x + margin_x, to_y + margin_y))
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
		game->player.xy.angle += game->player.move_direction
			* game->player.rotate_speed;
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
