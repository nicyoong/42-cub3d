/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:54:29 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 18:54:50 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_spriteproj	project_sprite(const t_game *game,
	const t_vec2d *t, t_image img)
{
	t_spriteproj	p;
	double			invy;
	int				baseh;

	invy = 1.0 / t->y;
	baseh = (int)(TILE_SIZE * invy * game->wall_prop.projected_wall);
	p.screenX = (int)(game->half_width * (1.0 + (t->x * invy)));
	p.height = baseh;
	if (p.height < 1)
		p.height = 1;
	p.width = (int)((double)p.height * img.img->width / img.img->height);
	if (p.width < 1)
		p.width = 1;
	return (p);
}

t_drawrect	draw_rect(const t_game *game, const t_spriteproj *p)
{
	t_drawrect	r;
	int			hh;

	hh = game->half_height;
	r.startY = clampi(-p->height / 2 + hh, 0, game->window_height - 1);
	r.endY = clampi(p->height / 2 + hh, 0, game->window_height - 1);
	r.startX = clampi(-p->width / 2 + p->screenX, 0, game->window_width - 1);
	r.endX = clampi(p->width / 2 + p->screenX, 0, game->window_width - 1);
	return (r);
}

int	tex_x_for_stripe(int stripe, const t_spriteproj *p, int texW)
{
	int	left;
	int	texx;

	left = -p->width / 2 + p->screenX;
	texx = (int)((stripe - left) * (double)texW / (double)p->width);
	return (clampi(texx, 0, texW - 1));
}

int	tex_y_for_y(int y, const t_game *game, const t_spriteproj *p, int texH)
{
	int	top;
	int	d;
	int	texy;

	top = -p->height / 2 + game->half_height;
	d = y - top;
	texy = (int)((double)d * (double)texH / (double)p->height);
	return (clampi(texy, 0, texH - 1));
}
