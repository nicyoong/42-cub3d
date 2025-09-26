/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:42:49 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 18:43:00 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	clampi(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

t_camera	make_camera(const t_game *game)
{
	t_camera	c;
	double		a;
	double		pa;

	a = game->player.xy.angle;
	pa = a + HALF_PI;
	c.dirX = cos(a);
	c.dirY = sin(a);
	c.planeX = cos(pa) * (FOV_ANGLE);
	c.planeY = sin(pa) * (FOV_ANGLE);
	return (c);
}

t_vec2d	sprite_delta(const t_game *game, double sx, double sy)
{
	t_vec2d	d;

	d.x = sx - game->player.xy.x;
	d.y = sy - game->player.xy.y;
	return (d);
}

double	inv_det(const t_camera *c)
{
	double	det;

	det = (c->planeX * c->dirY) - (c->dirX * c->planeY);
	if (fabs(det) < 1e-9)
		return (1e9);
	return (1.0 / det);
}

t_vec2d	camera_space(const t_vec2d *d, const t_camera *c, double invDet)
{
	t_vec2d	t;

	t.x = invDet * (c->dirY * d->x - c->dirX * d->y);
	t.y = invDet * (-c->planeY * d->x + c->planeX * d->y);
	return (t);
}
