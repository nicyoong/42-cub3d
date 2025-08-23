/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 20:52:28 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 20:52:37 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

uint32_t    put_shade(uint32_t color, double scale)
{
    int r;
    int g;
    int b;

    if (color == TRANSPARENT || scale <= SHADE_NUM)
        return (color);
    scale = SHADE_NUM / scale;
    r = ((color >> 16) & 0xFF) * scale;
    g = ((color >> 8) & 0xFF) * scale;
    b = (color & 0xFF) * scale;
    return ((r << 16) | (g << 8) | b);
}

uint32_t    get_color(t_image image, int x, int y)
{
    return (*(image.buffer + (x + y * image.img->size_line)));
}

void    draw_px(t_image image, int x, int y, uint32_t color)
{
    if (color != TRANSPARENT)
        *(image.buffer + (x + y * image.img->size_line)) = color;
}

void    rectangle(t_image image, t_img_prop *prop)
{
    int i;
    int j;

    j = 0;
    while (j < prop->height)
    {
        i = 0;
        while (i < prop->width)
        {
            draw_px(image, prop->x_offset + i, prop->y_offset + j, prop->color);
            i++;
        }
        j++;
    }
}

void    draw_cf(t_game *game)
{
    game->texture_properties.color = game->params.env[CEILING];
    game->texture_properties.x_offset = 0;
    game->texture_properties.y_offset = 0;
    game->texture_properties.height = game->half_height;
    game->texture_properties.width = game->window_width;
    rectangle(game->img, &game->texture_properties);
    game->texture_properties.color = game->params.env[CEILING];
    game->texture_properties.x_offset = 0;
    game->texture_properties.y_offset = game->half_height;
    game->texture_properties.height = game->half_height;
    game->texture_properties.width = game->window_width;
    rectangle(game->img, &game->texture_properties);
}