/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:28:03 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 20:28:14 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_image texture_id(t_game *game, int col)
{
    if (game->rays[col].hit_vertical)
    {
        if (game->rays[col].ray_left)
            return (game->wall_texture[WE]);
        return (game->wall_texture[EA]);
    }
    else
    {
        if (game->rays[col].ray_up)
            return (game->wall_texture[NO]);
        return (game->wall_texture[SO]);
    }
}

void    texture_prop(t_game *game, int col)
{
    game->texture_properties.y_offset = (game->half_height) - ((int)game->wall_prop.projected_height / 2);
    if (game->texture_properties.y_offset < 0)
        game->texture_properties.y_offset = 0;
    game->texture_properties.x_offset = col * RAY_STRIP;
    game->texture_properties.width = RAY_STRIP;
    game->texture_properties.height = (game->half_height) + ((int)game->wall_prop.projected_height / 2);
    if (game->texture_properties.height > game->window_height)
        game->texture_properties.height = game->window_height;
}

void    wall_dimension(t_game *game, int col)
{
    game->wall_prop.ray_distance = game->rays[col].xy.hypotenus * cos(game->rays[col].xy.angle - game->player.xy.angle);
    game->wall_prop.projected_height = (TILE_SIZE / game->wall_prop.ray_distance) * game->wall_prop.projected_wall;
}

void    texture_xy(t_game *game, int col, int row)
{
    if (game->rays[col].hit_vertical)
        game->wall_prop.x_color = (int)game->rays[col].xy.y % (TILE_SIZE);
    else
        game->wall_prop.x_color = (int)game->rays[col].xy.x % (TILE_SIZE);
    game->wall_prop.dist_from_top = row + ((int)game->wall_prop.projected_height / 2) - (game->half_height);
    game->wall_prop.y_color = game->wall_prop.dist_from_top * ((float)TILE_SIZE / (int)game->wall_prop.projected_height);
}

void    draw_walls(t_game *game)
{
    register int    col;
    register int    row;
    t_image         cur_img;

    col = 0;
    while (col < game->ray_nums)
    {
        wall_dimension(game, col);
        texture_prop(game, col);
        cur_img = texture_id(game, col);
        row = game->texture_properties.y_offset;
        while (row < game->texture_properties.height)
        {
            texture_xy(game, col, row);
            draw_px(game->img, col, row, put_shade(get_color(cur_img, game->wall_prop.x_color, game->wall_prop.y_color), game->rays[col].xy.hypotenus));
            row++;
        }
        col++;
    }
}
