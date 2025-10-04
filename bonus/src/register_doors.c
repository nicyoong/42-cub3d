/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:13:01 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 18:13:48 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	count_doors(t_game *game)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (game->params.map[y])
	{
		x = 0;
		while (game->params.map[y][x])
		{
			if (game->params.map[y][x] == DOOR_TILE)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	allocate_doors(t_game *game, int count)
{
	game->door_count = count;
	if (count == 0)
	{
		game->doors = NULL;
		return ;
	}
	game->doors = malloc(sizeof(t_door) * count);
	if (!game->doors)
		error("Door array allocation failed", game);
}

static void	init_doors(t_game *game)
{
	int		x;
	int		y;
	int		idx;
	t_door	*d;

	idx = 0;
	y = 0;
	while (game->params.map[y])
	{
		x = 0;
		while (game->params.map[y][x])
		{
			if (game->params.map[y][x] == DOOR_TILE)
			{
				d = &game->doors[idx++];
				d->x = x;
				d->y = y;
				d->state = DOOR_MIN;
				d->opening = 0;
				load_door_anim(game, d);
			}
			x++;
		}
		y++;
	}
}

void	register_doors(t_game *game)
{
	int	count;

	count = count_doors(game);
	allocate_doors(game, count);
	if (count > 0)
		init_doors(game);
}
