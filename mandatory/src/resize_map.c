/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:58:54 by tching            #+#    #+#             */
/*   Updated: 2025/08/22 12:59:04 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    reverse_matrix(char **ptr)
{
    int i;

    i = 0;
    free(ptr[i]);
    while (ptr[i])
    {
        ptr[i] = ptr[i + 1];
        i++;
    }
}

int wall_and_space(char *map_line)
{
    int i;

    i = 0;
    while (map_line[i])
        if (ft_strchr("0NEWS", map_line[i++]))
            return (0);
    return (1);
}
int is_invalid_tile(char **map, t_validation v)
{
    if (map[v.row][v.counter] == '0' \
        || (!v.counter \
        || ft_strchr("0NEWS", map[v.row][v.counter - 1])))
        return (0);
    if (v.row)
        if (v.counter <= v.col_limit[TOP_LINE])
            if (ft_strchr("0NEWS", map[v.row - 1][v.counter]) \
            || ft_strchr("0NEWS", map[v.row - 1][v.counter - 1]))
                return (0);
    if (v.row < v.total_row)
        if (v.counter <= v.col_limit[BOTTOM_LINE])
            if (ft_strchr("0NEWS", map[v.row + 1][v.counter]) \
            || ft_strchr("0NEWS", map[v.row + 1][v.counter - 1]))
                return (0);
    return (1);
}

void    resize_row(t_game *game)
{
    int row;
    int c;

    row = 0;
    c = 0;
    while (wall_and_space(game->params.map[row]))
        row++;
    while (c < row - 1)
    {
        reverse_matrix(game->params.map);
        c++;
    }
    row = count_vector((void **)game->params.map) - 1;
    c = row;
    while (walls_and_space (game->params.map[row]))
        row--;
    while (c > row + 1)
        reverse_matrix(game->params.map + c--);
}

void    resize_col(t_game *game)
{
    t_validation v;
    char    *tmp;

    v.row = -1;
    v.total_row = count_vector((void **)game->params.map) - 1;
    while (game->params.map[++v.row])
    {
        v.counter = ft_strlen(game->params.map[v.row]) - 1;
        if (v.row)
            v.col_limit[TOP_LINE] = ft_strlen(game->params.map[v.row - 1]) - 1;
        if (v.row < v.total_row)
            v.col_limit[BOTTOM_LINE] = ft_strlen(game->params.map[v.row + 1]) - 1;
        while (is_invalid_tile(game->params.map, v))
            v.counter--;
        if (v.counter == ft_strlen(game->params.map[v.row]) - 1)
            continue ; 
        tmp = ft_substr(game->params.map[v.row], 0, v.counter + 1);
        free_null((void *)&game->params.map[v.row]);
        game->params.map[v.row] = tmp;
    }    
}