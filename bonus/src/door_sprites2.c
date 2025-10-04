/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprites2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:57:47 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 20:00:39 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static int	transform_sprite_to_camera(t_game *game,
	double sx, double sy, t_vec2d *out_t)
{
	t_camera	cam;
	t_vec2d		delta;
	double		inv;

	cam = make_camera(game);
	delta = sprite_delta(game, sx, sy);
	inv = inv_det(&cam);
	*out_t = camera_space(&delta, &cam, inv);
	if (out_t->y <= 0.0001)
		return (0);
	return (1);
}

static void	build_projrect(t_game *game,
	t_image img, const t_vec2d *t, t_projrect *out)
{
	t_spriteproj	p;
	t_drawrect		r;

	p = project_sprite(game, t, img);
	r = draw_rect(game, &p);
	out->proj = p;
	out->rect = r;
	out->depth = t->y;
}

static void	draw_one_column(t_game *game,
	t_image img, const t_projrect *pr, int stripe)
{
	int			texx;
	int			y;
	int			texy;
	uint32_t	color;

	if (stripe < 0 || stripe >= game->window_width)
		return ;
	if (!(pr->depth < game->zbuffer[stripe]))
		return ;
	texx = tex_x_for_stripe(stripe, &pr->proj, img.img->width);
	y = pr->rect.starty;
	while (y <= pr->rect.endy)
	{
		texy = tex_y_for_y(y, game, &pr->proj, img.img->height);
		color = get_color(img, texx, texy);
		if ((color & 0xFF000000) != TRANSPARENCY)
			draw_px(game->img, stripe, y, color);
		y++;
	}
}

static void	draw_columns_span(t_game *game, t_image img, const t_projrect *pr)
{
	int	stripe;

	stripe = pr->rect.startx;
	while (stripe <= pr->rect.endx)
	{
		draw_one_column(game, img, pr, stripe);
		stripe++;
	}
}

void	draw_door_sprite(t_game *game, t_image img, double sx, double sy)
{
	t_vec2d		t;
	t_projrect	pr;

	if (!transform_sprite_to_camera(game, sx, sy, &t))
		return ;
	build_projrect(game, img, &t, &pr);
	draw_columns_span(game, img, &pr);
}
