/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:17:12 by tching            #+#    #+#             */
/*   Updated: 2025/08/07 21:29:41 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_game(t_game *game)
{
	if (game->window_height < 300 || game->window_width < 300)
		error("Invalid resolution, must be more than 300 x 300.", game);
	game->mlx = mlx_init();
	if (!game->mlx)
		error("MLX initialisation fail.", game);
	resource_load(game);
	load_rays(game);
}

void	resource_load(t_game *game)
{
	game->windowload = mlx_new_window(game->mlx, game->window_width, \
		game->window_height, "cub3D");
	if (!game->window)
		error("Window fail to open.", game);
	game->img.img = mlx_new_window(game->mlx, game->window_width, \
		game->window_height);
	if (!game->img.img)
		error("Failed image creation.", game);
	game->img.img->bpp /= 8;
	game->img.img->size_line /= game->img.img->bpp;
	game->img.buffer = (uint32_t *)game->img.img->data;
	load_texture(game);
	load_player(game);
}

int	load_sprite(t_image *image, void *mlx, char *path)
{
	int	height;
	int	width;

	image->img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!image->img)
		return (1);
	image->img->height = height;
	image->img->width = width;
	game->img.img->bpp /= 8;
    game->img.img->size_line /= game->img.img->bpp;
    game->img.buffer = (uint32_t *)game->img.img->data;
    return (0);
}

void	load_texture(t_game *game)
{
	int	res;

	res = load_sprite(game->wall_img + NO, game->mlx, \
		game->param.texture[NO]);
	res += load_sprite(game->wall_img + SO, game->mlx, \
		game->param.texture[SO]);
	res += load_sprite(game->wall_img + WE, game->mlx, \
		game->param.texture[WE]);
	res += load_sprite(game->wall_img + EA, game->mlx, \
		game->param.texture[EA]);
	if (res != EXIT_SUCCESS)
		error("Failed texture load.", game);
}
	
