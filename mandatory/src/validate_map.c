/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:17:36 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 21:17:49 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    empty_row(t_game *game)
{
    int i;
    int nl;
    int line_count;

    i = -1;
    nl = 0;
    line_count = count_vector((void **)game->params.map);
    while (game->map_cub[++i])
    {
        if (game->map_cub[i] == '\n')
        {
            nl++;
            if (game->map_cub[i + 1] == '\n' && nl < line_count)
                error("Empty row on map", game);
        }
    }
}

int sides_closed(char **map)
{
    if (ft_strchr(*map, '1') < ft_strchr(*map, '0'))
        return (0);
    if (ft_strchr(*map, '1') > ft_strchr(*map, '0') && ft_strchr(*map, '0'))
        return (0);
    return (1);
}

int surrounded(char **map, t_validation v)
{
    if (!v.row_num || v.row_num == v.total_row -1)
        return (0);
    if (map[v.row_num][v.col - 1] != '1' && !v.closed)
        return (0);
    if (v.row_num)
        if ((v.col >= v.col_limit[TOP_LINE] \
            || (map[v.row_num - 1][v.col - 1] == ' ') \
            || (map[v.row_num - 1][v.col] == ' ')))
            return (0);
    if (v.row_num < v.total_row - 1)
        if ((v.col >= v.col_limit[BOTTOM_LINE] \
            || (map[v.row_num + 1][v.col - 1] == ' ') \
            || (map[v.row_num + 1][v.col] == ' ')))
            return (0);
    return (1);
}

int row_validate(char **map, t_validation v)
{
    if (!sides_closed(map + v.row_num))
        return (EXIT_FAILURE);
    if (v.row_num)
        v.col_limit[TOP_LINE] = ft_strlen(map[v.row_num - 1]) - 1;
    if (v.row_num < v.total_row - 1)
        v.col_limit[BOTTOM_LINE] = ft_strlen(map[v.row_num + 1]) - 1;
    while (map[v.row_num][v.col])
    {
        if (!ft_strchr("0NEWS", map[v.row_num][v.col]))
        {
            if (map[v.row_num][v.col] != '1' && v.closed)
                return (EXIT_FAILURE);
            v.closed = 0;
        }
        else
        {
            if (!surrounded(map, v))
                return (EXIT_FAILURE);
            v.closed = 1;
        }
        v.col++;
    }
    return (EXIT_SUCCESS);
}
void    map_validate(t_game *game)
{
    t_validation    v;

    resize_row(game);
    resize_col(game);
    empty_row(game);
    ft_bzero(v.col_limit, sizeof(int) * 2);
    v.total_row = count_vector((void **)game->params.map);
    v.row_num = -1;
    v.col = 0;
    v.closed = 0;
    while (++v.row_num < v.total_row)
        if (row_validate(game->params.map, v))
            error("No surrounding walls", game);
    game->minimap_width = get_max_ls(game->params.map) * TILE_SIZE;
    game->minimap_height = count_vector((void **)game->params.map) * TILE_SIZE;
}

