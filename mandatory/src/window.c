/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:18:59 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 13:19:08 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    set_window(t_game *game)
{
    game->window = mlx_new_window(game->mlx, game->window_width, game->window_height, "cub3D");
    if (!game->window)
        error("Window failed to open", game);
}

void    set_images(t_game *game)
{
    game->img.img = mlx_new_image(game->mlx, game->window_width, game->window_height);
    if (!game->img.img)
        error("Image failed to load", game);
    game->img.img->bpp /= 8;
    game->img.img->size_line /= game->img.img->bpp;
    game->img.buffer = (uint32_t *)game->img.img->data;
}

void    set_sprite(t_image *image, void *mlx, char *path)
{
    int width;
    int height;

    image->img = mlx_xpm_file_to_image(mlx, path, &width, &height);
    if (!image->img)
        return (1);
    image->img->height = height;
    image->img->width = width;
    image->img->bpp /= 8;
    image->img->size_line /= image ->img->bpp;
    image->buffer = (uint32_t *)image->img->data;
    return (0);
}

void    set_texture(t_game *game)
{
    int status;

    status = set_sprite(game->wall_texture + NO, game->mlx, game->params.texture[NO]);
    status += set_sprite(game->wall_texture + SO, game->mlx, game->params.texture[SO]);
    status += set_sprite(game->wall_texture + WE, game->mlx, game->params.texture[WE]);
    status += set_sprite(game->wall_texture + EA, game->mlx, game->params.texture[EA]);
    if (status != EXIT_SUCCESS)
        error("Failed to load textures", game);
}
void    setup_game(t_game *game)
{
    if (game->window_width < 300 || ->window_height < 300)
        error("Resolution must be more than 300(H) x 300(W)", game);
    game->mlx = mlx_init();
    if (!game->mlx)
        error("Failed MLX initialization", game);
    set_window(game);
    set_images(game);
    set_texture(game);
    set_player(game);
    set_rays(game);
}
