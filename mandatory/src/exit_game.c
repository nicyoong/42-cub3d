/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:19:32 by tching            #+#    #+#             */
/*   Updated: 2025/08/20 21:19:34 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    free_null(void **ptr)
{
    if (*ptr != NULL)
        free(*ptr);
    *ptr = NULL;
}

void    cleanup_sprites(t_image *image, void *mlx, int x)
{
    int i;

    i = 0;
    while (i < x)
    {
        if (image[i].img)
            mlx_destroy_images(mlx, image[i].img);
        i++;
    }
}

void    cleanup_game(t_game *game)
{
    if (game->img.img)
        mlx_destroy_image(game->mlx, game->img.img);
    cleanup_sprites(game->wall_texture, game->mlx, TEXTURE_NUM);
    if (game->window)
        mlx_destroy_window(game->mlx, game->window);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free_null((void *)&game->mlx);
    }
}

void    free_game(t_game *game)
{
    if (game->file != INVALID_PTR)
        free_null((void *)&game->file);
    free_null((void *)&game->rays);
}

void    exit_game(t_game *game)
{
    free_matrix((void **)game->params.map, 0);
    free_matrix((void **)game->params.texture, 4);
    free_matrix((void **)game->params.color[0], 0);
    free_matrix((void **)game->params.color[1], 0);
    cleanup_game(game);
    free_game(game);
    exit(errno);
}



