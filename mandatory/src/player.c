/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 01:01:13 by tching            #+#    #+#             */
/*   Updated: 2025/08/10 01:01:24 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    load_player(t_game *game)
{
    int i;
    int j;

    i = 0;
    while(game->params.map[i])
    {
        j = 0;
        while (game->params.map[i][j])
        {
            if (ft_strchr("NSWE", game->params.map[i][j]))
            {
                rotation_angle(game, game->params.map[i][j]);
                game->player.xy.x = j * TILE_SIZE + (TILE_SIZE * 0.5);
                game->player.xy.y = i * TILE_SIZE + (TILE_SIZE * 0.5);
                game->params.map[i][j] = '0';
                return ;
            }
            j++;
        }
        i++;
    }
}

void    rotation_angle(t_game *game, char c)
{
    if (c == 'N')
        game->player.xy.angle = PI_AND_HALF_PI;
    else if (c == 'S')
        game->player.xy.angle = HALF_PI;
    else if (c == 'W')
        game->player.xy.angle = PI;
    else if (c == 'E')
        game->player.xy.angle = 0;
}

void    load_rays(t_game *game)
{
    game->ray_nums = game->window_width / RAY_STRIP;
    game->rays = malloc(sizeof(t_ray) * game->ray_nums);
    if (!game->rays)
        error("Failed malloc.", game);
}

size_t  get_max_ls(char **map)
{
    size_t  max_ls;
    int     i;

    max_ls = 0;
    i = 0;
    while (map[i])
    {
        if (ft_strlen(map[i] > max_ls))
            max_ls = ft_strlen(map[i]);
        i++;
    }
    return (max_ls);
}

