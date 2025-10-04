/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:21:42 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 20:02:34 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	destroy_image_safe(void *mlx, t_image *img)
{
	if (img && img->img)
	{
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
		img->buffer = NULL;
	}
}

static void	free_door_frames(t_game *game, t_door *d)
{
	int	f;

	if (!d->anim.frames)
		return ;
	f = 0;
	while (f < d->anim.frame_count)
	{
		destroy_image_safe(game->mlx, &d->anim.frames[f]);
		f++;
	}
	free(d->anim.frames);
	d->anim.frames = NULL;
	d->anim.frame_count = 0;
	d->anim.current = 0;
	d->anim.timer = 0.0;
}

static void	free_all_doors(t_game *game)
{
	int		i;
	t_door	*d;

	i = 0;
	while (i < game->door_count)
	{
		d = &game->doors[i];
		free_door_frames(game, d);
		i++;
	}
}

void	cleanup_doors(t_game *game)
{
	if (!game || !game->doors)
		return ;
	free_all_doors(game);
	free(game->doors);
	game->doors = NULL;
	game->door_count = 0;
}

void	cleanup_zbuffer(t_game *game)
{
	if (!game)
		return ;
	if (game->zbuffer)
	{
		free(game->zbuffer);
		game->zbuffer = NULL;
	}
}
