/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:17:12 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 22:39:00 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	setup_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		//ERROR
	resource_load(game);
}

void	resource_load(t_game *game)
{
	game->windowload = mlx_new_window(game->mlx, game->window_width, \
		game->window_height, "cub3D");
	if (!game->window)
		//ERRORMSG
	game->img.img = mlx_new_window(game->mlx, game->window_width, \
		game->window_height);
	if (!game->img.img)
		//ERRORMSG
	game->img.img->bpp /= 8;
	game->img.img->size_line /= game->img.img->bpp;
	game->img.buffer = (uint32_t *)game->img.img->data;
	load_texture(game);
	//load_player(game);
}

int	load_image(t_image *image, void *mlx, char *path)
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

void	load texture(t_game *game)
{
	int	res;

	res = //TBC
	if (res != EXIT_SUCCESS)
		//ERRORMSG
}
	
