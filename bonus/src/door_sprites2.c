/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprites2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:57:47 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:20:46 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	draw_sprite_columns(t_game *game, t_image img,
	const t_spriteproj *p, const t_drawrect *r, double depth)
{
	int			stripe;
	int			texx;
	int			y;
	int			texy;
	uint32_t	color;

	stripe = r->startx;
	while (stripe <= r->endx)
	{
		if (stripe >= 0 && stripe < game->window_width)
		{
			if (depth < game->zbuffer[stripe])
			{
				texx = tex_x_for_stripe(stripe, p, img.img->width);
				y = r->starty;
				while (y <= r->endy)
				{
					texy = tex_y_for_y(y, game, p, img.img->height);
					color = get_color(img, texx, texy);
					if ((color & 0xFF000000) != TRANSPARENCY)
						draw_px(game->img, stripe, y, color);
					y++;
				}
			}
		}
		stripe++;
	}
}

void	draw_door_sprite(t_game *game, t_image img, double sx, double sy)
{
	t_camera		cam;
	t_vec2d			delta;
	double			inv;
	t_vec2d			t;
	t_spriteproj	proj;
	t_drawrect		rect;

	cam = make_camera(game);
	delta = sprite_delta(game, sx, sy);
	inv = inv_det(&cam);
	t = camera_space(&delta, &cam, inv);
	if (t.y <= 0.0001)
		return ;
	proj = project_sprite(game, &t, img);
	rect = draw_rect(game, &proj);
	draw_sprite_columns(game, img, &proj, &rect, t.y);
}
