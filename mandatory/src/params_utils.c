/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:55:15 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 12:55:29 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_map(char *file, t_game *game)
{
    int chars;
    int lines;

    lines = 0;
    chars = 0;
    game->params.map = ft_split(file, '\n');
    if (!game->params.map)
        error("Failed load map", game);
    while (game->params.map[lines])
        chars += ft_strlen(game->params.map[lines++]);
    return ((chars + lines) - 1);
}

int get_env_color(char *file, int identifier, t_game *game)
{
    int n;
    int i;
    char    *color;

    i = 1;
    while (file[i] && file[i] != '\n' && ft_isspace(file[i]))
        i++;
    if ((i - 1) == 0)
        error("Wrong identifier", game);
    n = 0;
    if (game->params.color[identifier])
        error("Duplicate identifer", game);
    while (file[n] && file[n] != '\n')
        n++;
    color = ft_substr(file + 1, 0 , n);
    if (!color)
        error("Failed color load", game);
    game->params.color[identifier] = ft_split(color, ',');
    free_null((void *)&color);
    if (!game->params.color[identifier])
        error("Failed env color", game);
    return (n);
}

int get_texture(char *file, int identifier, t_game *game)
{
    int n;
    int i;

    i = 2;
    while (file[i] && ft_isspace(file[i]) && file[i] != '\n')
        i++;
    if ((i - 2) == 0)
        error("Wrong identifier", game);
    n = 0;
    if (game->params.texture[identifier])
        error("Duplicate identifier", game);
    while (file[n] && file[n] != '\n')
        n++;
    game->params.texture[identifier] = ft_substr(file + 3, 0, n - 3);
    if (!game->params.texture[identifier])
        error("Failed texture load", game);
    return (n);
}

int close_window(t_game *game)
{
    printf("Closed window.\n");
    exit_game(game);
    return (0);
}

double  hypotenuse(double x, double y)
{
    return (sqrt( x * x + y * y));
}

