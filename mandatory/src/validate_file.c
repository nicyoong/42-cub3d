/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:16:26 by tching            #+#    #+#             */
/*   Updated: 2025/09/26 22:48:44 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	char_player_validate(t_game *game)
{
	int		i;
	int		j;
	int		player;

	i = 0;
	player = 0;
	while (game->params.map[i])
	{
		j = 0;
		while (game->params.map[i][j])
		{
			if (!ft_strchr("10NSEW ", game->params.map[i][j]))
				error("Invalid char on map", game);
			if (ft_strchr("NSEW", game->params.map[i][j]))
				player++;
			if (player > 1)
				error("Two or more player is not allowed", game);
			j++;
		}
		i++;
	}
	if (player == 0)
		error("There is no player", game);
}

void	color_validate(t_game *game, int env)
{
	int		i;
	int		j;
	int		color;

	if (count_vectors((void **)game->params.rgb[env]) != 3)
		error("Invalid argument for color identifier", game);
	i = -1;
	while (game->params.rgb[env][++i])
	{
		j = -1;
		while (game->params.rgb[env][i][++j])
			if (!ft_isspace(game->params.rgb[env][i][j])
				&& !ft_isdigit(game->params.rgb[env][i][j]))
				error("Invalid identifier", game);
		color = ft_atoi(game->params.rgb[env][i]);
		if (color < 0 || color > 255)
			error("Invalid RGB", game);
		game->params.env[env] |= color;
		if (i < 2)
			game->params.env[env] <<= 8;
	}
}

void	validate_file(t_game *game)
{
	color_validate(game, FLOOR);
	color_validate(game, CEILING);
	char_player_validate(game);
	map_validate(game);
}
