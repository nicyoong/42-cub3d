/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:15:36 by tching            #+#    #+#             */
/*   Updated: 2025/09/26 22:33:29 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_texture(char *file, int *identifier)
{
	if (!ft_strncmp(file, "NO", 2))
		*identifier = NO;
	else if (!ft_strncmp(file, "SO", 2))
		*identifier = SO;
	else if (!ft_strncmp(file, "WE", 2))
		*identifier = WE;
	else if (!ft_strncmp(file, "EA", 2))
		*identifier = EA;
	else
		return (0);
	return (1);
}

int	is_color(char *file, int *identifier)
{
	if (!ft_strncmp(file, "F", 1))
		*identifier = FLOOR;
	else if (!ft_strncmp(file, "C", 1))
		*identifier = CEILING;
	else
		return (0);
	return (1);
}

void	set_params(t_game *game)
{
	int		i;
	int		identifier;
	int		elements;

	i = 0;
	elements = 0;
	while (game->file[i])
	{
		while (game->file[i] == '\n' && game->file[i])
			i++;
		if (is_texture(game->file + i, &identifier))
			i += get_texture(game->file + i, identifier, game);
		else if (is_color(game->file + i, &identifier))
			i += get_env_color(game->file + i, identifier, game);
		else if (!game->params.map && elements == 6)
		{
			game->map_cub = game->file + i;
			i += get_map(game->file + i, game);
		}
		else if (game->file[i])
			error ("Configuration file is invalid", game);
		if (!game->params.map)
			elements++;
	}
}
