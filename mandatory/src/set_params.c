/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 00:45:41 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 00:45:50 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int is_texture(char *file, int *identifier)
{
    if (!ft_strncmp(file, "NO", 1))
        *identifier = NO;
    else if (!ft_strncmp(file, "WE", 1))
        *identifier = WE;
    else if (!ft_strncmp(file, "SO", 1))
        *identifier = SO;
    else if (!ft_strncmp(file, "EA", 1))
        *identifier = EA;
    else
        return (0);
    return (1);
}

int is_color(char *file, int *identifier)
{
    if (!ft_strncmp(file, "F", 1))
        *identifier = FLOOR;
    else if (!ft_strncmp(file, "C", 1))
        *identifier = CEILING;
    else
        return (0);
    return (1);
}

void    set_params(t_game *game)
{
    int i;
    int element;
    int id;

    i = 0;
    element = 0;
    while (game->file[i])
    {
        while (game->file[i] && game->file[i] == '\n')
            i++;
        if (is_texture(game->file + i, &id))
            i += get_texture(game->file + i, id, game);
        else if (is_color(game->file + i, &id))
            i += get_env_color(game->file + i, id, game);
        else if (element == 6 && !game->params.map)
        {
            game->map_cub = game->file + i;
            i += get_map(game->file + i, game);
        }
        else if (game->file[i])
            error("Configuration file is invalid", game);
        if (!game->params.map)
            element++;
    }
}