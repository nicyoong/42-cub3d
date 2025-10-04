/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:15:52 by tching            #+#    #+#             */
/*   Updated: 2025/09/27 13:06:10 by tiara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_game(t_game *game)
{
	if (game->file != (void *)-1)
		free_null((void *)&game->file);
	free_null((void *)&game->rays);
}

void	cleanup_game(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	cleanup_sprites(game->wall_texture, game->mlx, TEXTURES_NUM);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free_null((void *)&game->mlx);
	}
}

void	exit_game(t_game *game)
{
	free_matrix((void **)game->params.map, 0);
	free_matrix((void **)game->params.texture, 4);
	free_matrix((void **)game->params.rgb[0], 0);
	free_matrix((void **)game->params.rgb[1], 0);
	cleanup_game(game);
	free_game(game);
	exit(0);
}

int	close_window(t_game *game)
{
	printf("Closed window.\n");
	exit_game(game);
	return (0);
}

void	cleanup_sprites(t_image *images, void *mlx, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		if (images[i].img)
			mlx_destroy_image(mlx, images[i].img);
		i++;
	}
}
