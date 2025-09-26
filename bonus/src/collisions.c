/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:04:17 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:47:13 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	has_wall_for_raycast(t_game *game, double x, double y)
{
	int		col;
	int		row;
	char	tile;

	col = (int)floor(x / TILE_SIZE);
	row = (int)floor(y / TILE_SIZE);
	if (row < 0 || row >= (int)count_vectors((void **)game->params.map))
		return (1);
	if (col < 0 || col >= (int)ft_strlen(game->params.map[row]))
		return (1);
	tile = game->params.map[row][col];
	return (tile == '1');
}

int	has_blocking_tile(t_game *game, double x, double y)
{
	int		col;
	int		row;
	char	tile;
	int		i;

	col = (int)floor(x / TILE_SIZE);
	row = (int)floor(y / TILE_SIZE);
	if (row < 0 || row >= (int)count_vectors((void **)game->params.map))
		return (1);
	if (col < 0 || col >= (int)ft_strlen(game->params.map[row]))
		return (1);
	tile = game->params.map[row][col];
	if (tile == '1')
		return (1);
	if (tile == DOOR_TILE)
	{
		i = 0;
		while (i < game->door_count)
		{
			if (game->doors[i].x == col && game->doors[i].y == row)
				return (game->doors[i].state < DOOR_MAX);
			i++;
		}
	}
	return (0);
}

int	collide_diagonal(t_game *game, double to_x, double to_y)
{
	double		x_diff;
	double		y_diff;

	x_diff = to_x - game->player.xy.x;
	y_diff = to_y - game->player.xy.y;
	if (fabs(x_diff) <= TILE_SIZE && fabs(y_diff) <= TILE_SIZE)
	{
		if (has_blocking_tile(game, to_x - x_diff, to_y))
			return (1);
		if (has_blocking_tile(game, to_x, to_y - y_diff))
			return (1);
	}
	return (0);
}
