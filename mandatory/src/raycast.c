/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:16:17 by tching            #+#    #+#             */
/*   Updated: 2025/09/26 22:55:03 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_distance(t_game *game, t_ray *ray)
{
	int	d;

	if (game->ray_prop[HORIZONTAL].is_hit == true)
		game->ray_prop[HORIZONTAL].hypo = hypotenuse(
				(game->ray_prop[HORIZONTAL].x_int
					- game->player.xy.x),
				(game->ray_prop[HORIZONTAL].y_int
					- game->player.xy.y));
	if (game->ray_prop[VERTICAL].is_hit == true)
		game->ray_prop[VERTICAL].hypo = hypotenuse(
				(game->ray_prop[VERTICAL].x_int
					- game->player.xy.x),
				(game->ray_prop[VERTICAL].y_int
					- game->player.xy.y));
	d = game->ray_prop[VERTICAL].hypo < game->ray_prop[HORIZONTAL].hypo;
	ray->xy.x = game->ray_prop[d].x_int;
	ray->xy.y = game->ray_prop[d].y_int;
	ray->xy.hypo = game->ray_prop[d].hypo;
	ray->hit_vertical = d;
}

void	raycast(t_game *game, t_ray *ray)
{
	game->ray_prop[VERTICAL].is_hit = false;
	game->ray_prop[HORIZONTAL].is_hit = false;
	game->ray_prop[VERTICAL].hypo = __FLT_MAX__;
	game->ray_prop[HORIZONTAL].hypo = __FLT_MAX__;
	construct_ray(ray);
	vertical_cast(game, game->ray_prop + VERTICAL, ray);
	horizontal_cast(game, game->ray_prop + HORIZONTAL, ray);
	calculate_distance(game, ray);
}

void	cast_all_rays(t_game *game)
{
	int		i;
	float	angle;

	i = 0;
	angle = game->player.xy.angle - (FOV_ANGLE / 2);
	while (i < game->ray_num)
	{
		game->rays[i].xy.angle = angle;
		raycast(game, game->rays + i);
		angle += FOV_ANGLE / game->ray_num;
		i++;
	}
}
