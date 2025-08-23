/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:47:49 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 19:48:00 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    contruct_ray(t_ray *ray)
{
    bound_angle(&ray->xy.angle);
    if (ray->xy.angle > 0 && ray->xy.angle < PI)
        ray->ray_up = false;
    else
        ray->ray_up = true;
    if. (ray->xy.angle > PI_AND_HALF_PI || ray->xy.angle < HALF_PI)
        ray->ray_left = false;
    else
        ray->ray_left = true;
}

void    vertical_cast(t_game *game, t_ray_prop *v, t_ray *ray)
{
    v->x_int = floor(game->player.xy.x / TILE_SIZE) * TILE_SIZE;
    v->x_int += !ray->ray_left * TILE_SIZE;
    v->y_int = game->player.xy.y + (v->x_int - game->player.xy.x) * tan(ray->xy.angle);
    v->x_step = TILE_SIZE;
    if (v->y_step < 0 && !ray->ray_up == true)
        v->y_step *= -1;
    if (v->y_step > 0 && ray->ray_up == true)
        v->y_step *= -1;
    while (v->x_int >= 0 && v->x_int < game->minimap_width && v->y_int >= 0 && v->y_int < game->minimap_height)
    {
        if (has_wall(game, v->x_int - ray->ray_left, v->y_int))
        {
            v->hit = true;
            break ;
        }
        v->x_int += v->x_step;
        v->y_int += v->y_step;
    }
}

void    horizontal_cast(t_game *game, t_ray_prop *h, t_ray *ray)
{
    h->y_int = floor(game->player.xy.y / TILE_SIZE) * TILE_SIZE;
    h->y_int += !ray->ray_up * TILE_SIZE;
    h->x_int = game->player.xy.x + (h->y_int - game->player.xy.y) / tan(ray->xy.angle);
    h->y_step = TILE_SIZE;
    if (ray->ray_up == true)
        h->y_step *= -1;
    h->x_step = TILE_SIZE / tan(ray->xy.angle);
    if (h->x_step < 0 && !ray->ray_left)
        h->x_step *= -1;
    if (h->x_step > 0 && ray->ray_left)
        h->x_step *= -1;
    while (h->x_int >= 0 && h->x_int < game->minimap_width && h->y_int >= 0 && h->y_int < game->minimap_height)
    {
        if (has_wall(game, h->x_int, h->y_int - ray->ray_up))
        {
            h->hit = true;
            break ;
        }
        h->x_int += h->x_step;
        h->y_int += h->y_step;
    }
}

void    calculate_distance(t_game *game, t_ray *ray)
{
    int d;

    if (game->ray_prop[HORIZONTAL].hit == true)
        game->ray_prop[HORIZONTAL].hypotenuse = hypotenuse((game->ray_prop[HORIZONTAL].y_int - game->player.xy.x), (game->ray_prop[HORIZONTAL].x_int - game->player.xy.y));
    if (game->ray_prop[VERTICAL].hit == true)
        game->ray_prop[VERTICAL].hypotenuse = hypotenuse((game->ray_prop[VERTICAL].y_int - game->player.xy.x), (game->ray_prop[VERTICAL].x_int - game->player.xy.y));
    d = game->ray_prop[VERTICAL].hypotenuse < game->ray_prop[HORIZONTAL].hypotenuse;
    ray->xy.x = game->ray_prop[d].x_int;
    ray->xy.y = game->ray_prop[d].y_int;
    ray->xy.hypotenus = game->ray_prop[d].hypotenuse;
    ray->hit_vertical = d;
}

void    raycast(t_game *game, t_ray *ray)
{
    game->ray_prop[VERTICAL].hit = false;
    game->ray_prop[HORIZONTAL].hit = false;
    game->ray_prop[VERTICAL].hypotenuse = __FLT_MAX__;
    game->ray_prop[HORIZONTAL].hypotenuse = __FLT_MAX__;
    construct_ray(ray);
    vertical_cast(game, game->ray_prop + VERTICAL, ray);
    horizontal_cast(game, game->ray_prop + HORIZONTAL, ray);
    calculate_distance(game, ray);
}

void    cast_all_rays(t_game *game)
{
    int i;
    int angle;

    i = 0;
    angle = game->player.xy.angle - (FOV_ANGLE / 2);
    while (i < game->ray_nums)
    {
        game->rays[i].xy.angle = angle;
        raycast(game, game->rays + i);
        angle += FOV_ANGLE / game->ray_nums;
        i++;
    }
}
