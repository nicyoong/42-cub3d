/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:15:21 by tching            #+#    #+#             */
/*   Updated: 2025/09/26 22:15:23 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	player_rotate_angle(t_game *game, char c)
{
	if (c == 'N')
		game->player.xy.angle = PI_PLUS_HALF_PI;
	else if (c == 'S')
		game->player.xy.angle = HALF_PI;
	else if (c == 'W')
		game->player.xy.angle = PI;
	else if (c == 'E')
		game->player.xy.angle = 0;
}

void	set_player(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->params.map[i])
	{
		j = 0;
		while (game->params.map[i][j])
		{
			if (ft_strchr("NSWE", game->params.map[i][j]))
			{
				player_rotate_angle(game, game->params.map[i][j]);
				game->player.xy.x = j * TILE_SIZE + (TILE_SIZE * 0.5);
				game->player.xy.y = i * TILE_SIZE + (TILE_SIZE * 0.5);
				game->params.map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	set_rays(t_game *game)
{
	game->ray_num = game->window_width / RAY_STRIP;
	game->rays = malloc(sizeof(t_ray) * game->ray_num);
	if (!game->rays)
		error("Failed rays malloc", game);
}

size_t	get_max_ls(char **map)
{
	size_t	max;
	int		i;

	max = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}
