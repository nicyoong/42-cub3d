/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_doors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:21:42 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:43:14 by nyoong           ###   ########.fr       */
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

void	cleanup_doors(t_game *game)
{
	int		i;
	t_door	*d;
	int		f;

	if (!game)
		return ;
	if (!game->doors)
		return ;
	i = 0;
	while (i < game->door_count)
	{
		d = &game->doors[i];
		if (d->anim.frames)
		{
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
		i++;
	}
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
