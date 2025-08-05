/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:22:30 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 21:31:12 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_game(t_game *game)
{
	if (game->file != INVALID_PTR)
		free_null((void *)&game->file);
}

static void	end_game(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	//
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free_null((void *)&game->mlx);
	}
}

static void	destroy_textures(t_image *images, vois *mlx, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (images[i].img)
			mlx_destroy_image(mlx, images[i].img);
		i++;
	}
}

void	exit_game(t_game *game)
{
	//
	end_game(game);
	free_game(game);
}
