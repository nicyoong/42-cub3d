/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:05:28 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:05:28 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	construct_ray(t_ray *ray)
{
	bound_angle(&ray->xy.angle);
	if (ray->xy.angle > 0 && ray->xy.angle < PI)
		ray->ray_up = false;
	else
		ray->ray_up = true;
	if (ray->xy.angle > PI_PLUS_HALF_PI || ray->xy.angle < HALF_PI)
		ray->ray_left = false;
	else
		ray->ray_left = true;
}

void	vertical_cast(t_game *game, t_rays_prop *v, t_ray *ray)
{
	v->x_int = floor(game->player.xy.x / TILE_SIZE) * TILE_SIZE;
	v->x_int += !ray->ray_left * TILE_SIZE;
	v->y_int = game->player.xy.y
		+ (v->x_int - game->player.xy.x) * tan(ray->xy.angle);
	v->x_step = TILE_SIZE;
	if (ray->ray_left == true)
		v->x_step *= -1;
	v->y_step = TILE_SIZE * tan(ray->xy.angle);
	if (v->y_step < 0 && !ray->ray_up == true)
		v->y_step *= -1;
	if (v->y_step > 0 && ray->ray_up == true)
		v->y_step *= -1;
	while (v->x_int >= 0 && v->x_int < game->minimap_width
		&& v->y_int >= 0 && v->y_int < game->minimap_height)
	{
		if (has_wall_for_raycast(game, v->x_int - ray->ray_left,
				v->y_int))
		{
			v->is_hit = true;
			break ;
		}
		v->x_int += v->x_step;
		v->y_int += v->y_step;
	}
}

void	horizontal_cast(t_game *game, t_rays_prop *h, t_ray *ray)
{
	h->y_int = floor(game->player.xy.y / TILE_SIZE) * TILE_SIZE;
	h->y_int += !ray->ray_up * TILE_SIZE;
	h->x_int = game->player.xy.x
		+ (h->y_int - game->player.xy.y) / tan(ray->xy.angle);
	h->y_step = TILE_SIZE;
	if (ray->ray_up == true)
		h->y_step *= -1;
	h->x_step = TILE_SIZE / tan(ray->xy.angle);
	if (h->x_step < 0 && !ray->ray_left)
		h->x_step *= -1;
	if (h->x_step > 0 && ray->ray_left)
		h->x_step *= -1;
	while (h->x_int >= 0 && h->x_int < game->minimap_width
		&& h->y_int >= 0 && h->y_int < game->minimap_height)
	{
		if (has_wall_for_raycast(game, h->x_int, h->y_int
				- ray->ray_up))
		{
			h->is_hit = true;
			break ;
		}
		h->x_int += h->x_step;
		h->y_int += h->y_step;
	}
}
