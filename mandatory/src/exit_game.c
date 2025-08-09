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

void	free_null(void **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
}

static void	free_game(t_game *game)
{
	if (game->file != INVALID_PTR)
		free_null((void *)&game->file);
}

static void	end_game(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	destroy_textures(game->wall_img, game->mlx, TEXTURE_NUM);
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
void	free_matrix(void **matrix, size_t size)
{
	size_t	i;

	i = -1;
	if (matrix != NULL)
	{
		if (size)
		{
			while (++i < size)
				free_null((void *)&matrix[i]);
		}
		else
			while (matrix[++i])
				free_null((void *)&matrix[i]);
			free_null((void *)&matrix);
	}
}

void	exit_game(t_game *game)
{
	free_matrix((void **)game->params.texture, 4);
	free_matrix((void **)game->params.map, 0);
	free_matrix((void **)game->params.color[0], 0);
	free_matrix((void **)game->params.color[1], 0);
	end_game(game);
	free_game(game);
	exit (errno);
}

void	error_game(char	*message, *game)
{
	printf("Error\n%s.\n%s\n", message, sterror(errno));
	free_matrix((void **)game->params.texture, 4);
	free_matrix((void **)game->params.map, 0);
	free_matrix((void **)game->params.color[0], 0);
	free_matrix((void **)game->params.color[1], 0);
	end_game(game);
	free_game(game);
	exit (errno);
}


