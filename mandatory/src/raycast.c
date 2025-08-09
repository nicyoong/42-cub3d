/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 01:35:12 by tching            #+#    #+#             */
/*   Updated: 2025/08/10 01:35:25 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    cast_all_rays(t_game *game)
{
    int i;
    float   angle;

    i = 0;
    angle = game->player.xy.angle - (FOV_ANGLE / 2);
    while (i < game->ray_nums)
    {
        game->rays[i].xy.angle = angle;
        cast_ray(game, game->rays + i);
        angle += FOV_ANGLE / game->rays_nums;
        i++;
    }
}

void    cast_ray(t_game *game, t_ray *ray)
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

void    vertical_cast(t_game *game, t_ray **ver, t_ray *ray)
{
    ver->x_int = floor(game->player.xy.x / TILE_SIZE) * TILE_SIZE;
    ver->x_int += !ray->ray_left * TILE_SIZE;
    ver->y_int = game->player.xy.y + (ver->x_int - game->player.xy.x) * tan(ray->xy.angle);
    ver->x_step = TILE_SIZE;
    if (ray->ray_left == true)
        ver->x_step *= -1;
    ver->y_step = TILE_SIZE * tan(ray->xy.angle);
    if (ver->y_step < 0 && !ray->ray_up == true)
        ver->y_step *= -1;
    if (ver->y_step > 0 && ray->ray_up == true)
        ver->y_step *= -1
    while (ver->x_int >= 0 && ver->x_int < game->minimap_width \
        && ver->y_int >= 0 && ver->y_int < game->minimap_height)
    {
        if (wall_at(game, ver->x_int - ray->ray_left, ver->y_int))
        {
            ver->hit = true;
            break ;
        }
        ver->x_int += ver->x_step;
        ver->y_int += ver->y_step;
    }
}

void    horizontal_cast(t_game *game, t_ray **hor, t_ray *ray)
{
    hor->y_int = floor(game->player.xy.y / TILE_SIZE) * TILE_SIZE;
    hor->y_int += !ray->ray_up * TILE_SIZE;
    hor->x_int = game->player.xy.x + (hor->y_int - game->player.xy.y) / tan(ray->xy.angle);
    hor->y_step = TILE_SIZE;
    if (ray->ray_up == true)
        hor->y_step *= -1;
    hor->x_step = TILE_SIZE / tan(ray->xy.angle);
    if (hor->x_step < 0 && !ray->ray_left)
        hor->x_step *= -1;
    if (hor->x_step > 0 && ray->ray_left)
        hor->x_step *= -1
    while (hor->x_int >= 0 && hor->x_int < game->minimap_width \
        && hor->y_int >= 0 && hor->y_int < game->minimap_height)
    {
        if (wall_at(game, hor->x_int, hor->y_int - ray->ray_up))
        {
            hor->hit = true;
            break ;
        }
        hor->x_int += hor->x_step;
        hor->y_int += hor->y_step;
    }
}

void    calculate_distance(t_game *game, t_ray *ray)
{
    int closer;

    if (game->ray_prop[HORIZONTAL].hit == true)
        game->ray_prop[HORIZONTAL].hypotenuse = hypotenuse( \
            (game->ray_prop[HORIZONTAL].x_int - game->player.xy.x), \
            (game->ray_prop[HORIZONTAL].y_int - game->player.xy.y));
    if (game->ray_prop[VERTICAL].hit == true)
        game->ray_prop[VERTICAL].hypotenuse = hypotenuse( \
            (game->ray_prop[VERTICAL].x_int - game->player.xy.x), \
            (game->ray_prop[VERTICAL].y_int - game->player.xy.y));
    closer = game->ray_prop[VERTICAL].hypotenuse < game->ray_prop[HORIZONTAL].hypotenuse;
    ray->xy.x = game->ray_prop[closer].x_int;
    ray->xy.y = game->ray_prop[closer].y_int;
    ray->xy.hypotenus = game->ray_prop[closer].hypotenuse;
    ray->hit_vertical = closer;
}

double  hypotenuse(double x, double y)
{
    return (sqrt((x * x) + (y * y)));
}

void    get_angle(double *angle)
{
    *angle = remainder(*angle, DOUBLE_PI);
    if (*angle < 0)
        *angle = DOUBLE_PI + *angle;
}

void    construct_ray(t_ray *ray)
{
    get_angle(&ray->xy.angle);
    if (ray->xy.angle > 0 && ray->xy.angle < PI)
        ray->ray_up = false;
    else
        ray->ray_up = true;
    if (ray->xy.angle > PI_AND_HALF_PI || ray->xy.angle < HALF_PI)
        ray->ray_left = false;
    else
        ray->ray_left = true;
}
