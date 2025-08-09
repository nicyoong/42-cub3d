/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:41:25 by tching            #+#    #+#             */
/*   Updated: 2025/08/09 15:41:38 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_params(t_game *game)
{
    int i;
    int identifier;
    int elements;

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
            game->map = game->file + i;
            i += get_map(game->file + i, game);
        }
        else if (game->file[i])
            error("Invalid file config.", game);
        if (!game->params.map)
            elements++;
    }
}

int is_texture(char *file, int identifier)
{
    if (!ft_strncmp(file, "NORTH", 2))
        *identifier = NORTH;
    else if (!ft_strncmp(file, "SOUTH", 2))
        *identifier = SOUTH;
    else if (!ft_strncmp(file, "EAST", 2))
        *identifier = EAST;
    else if (!ft_strncmp(file, "WEST", 2))
        *identifier = WEST;
    else
        return (0);
    return (1);
}

int is_color(char *file, int identifier)
{
    if (!ft_strncmp(file, "FLOOR", 2))
        *identifier = FLOOR;
    else if (!ft_strncmp(file, "CEILING", 2))
        *identifier = CEILING;
    else
        return (0);
    return (1);
}

int get_texture(char *file, int identifier, t_game *game)
{
    int i;
    int n;

    i = 2;
    n = 0;
    while (ft_isspace(file[i]) && file[i] && file[i] != '\n')
        i++;
    if ((i - 2) == 0)
        error("Invalid identifier.", game);
    if (game->params.texture[identifier])
        error("Duplicate identifier.", game);
    while (file[n] != '\n' && file[n])
        n++;
    game->params.texture[identifier] = ft_substr(file + 3, 0, n -3);
    if (game->params.texture[identifier])
        error("Invalid texture.", game);
    return (n);
}

int get_map(char *file, t_game *game)
{
    int lines;
    int characters;

    lines = 0;
    characters = 0;
    game->params.map = ft_split(file, '\n');
    if (!game->params.map)
        error("Invalid file.", game);
    while (game->params.map[lines])
        characters += ft_strlen(game->params.map[lines++]);
    return ((characters + lines) - 1);
}

int get_env_color(char *file, int identifier, t_game game)
{
    int n;
    int i;
    char    *color;

    n = 0;
    i = 1;
    while (ft_isspace(file[i] && file[i]) && file[i] != '\n')
        i++;
    if ((i - 1) == 0)
    error("Invalid identifier", game);
    if (game->params.color[identifier])
        error("Duplicate identifer.", game);
    while (file[n] != '\n' && file[n])
        n++;
    color = ft_substr(file + 1, 0, n);
    if (!color)
        error("Failed to allocate memory for RGB substring.", game);
    game->params.color[identifier] = ft_split(color, ',');
    free_null((void *)&color);
    if (!game->params.color[identifier])
        error("Failed to allocate memory for RGB components", game);
    return (n);
}