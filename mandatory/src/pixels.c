/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:39:40 by tching            #+#    #+#             */
/*   Updated: 2025/08/09 14:49:39 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_color(t_image image, int x, int y)
{
	return (*(image.buffer + (x + y * image.img->size_line)));
}

uint32_t	put_shade(uint32_t color, double scale)
{
	int	r;
	int	g;
	int	b;

	if (scale <= SHADE_NUM || color == TRANSPARENT)
		return (color);
	scale = SHADE_NUM / scale;
	r = ((color >> 16) & 0xFF) * scale;
	g = ((color >> 8) & 0xFF) * scale;
	b = (color & 0xFF) * scale;
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel(t_image image, int x, int y, uint32_t color)
{
	if (color != TRANSPARENT)
		*(image.buffer + (x + y * image.img->size_line)) = color;
}
