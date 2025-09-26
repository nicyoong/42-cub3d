/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:06:37 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:39:00 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

t_image	texture_id(t_game *game, int col)
{
	if (game->rays[col].hit_vertical)
	{
		if (game->rays[col].ray_left)
			return (game->wall_texture[WE]);
		return (game->wall_texture[EA]);
	}
	else
	{
		if (game->rays[col].ray_up)
			return (game->wall_texture[NO]);
		return (game->wall_texture[SO]);
	}
}

void	texture_prop(t_game *game, int col)
{
	game->texture_prop.y_offset = (game->half_height)
		- ((int)game->wall_prop.projected_height / 2);
	if (game->texture_prop.y_offset < 0)
		game->texture_prop.y_offset = 0;
	game->texture_prop.x_offset = col * RAY_STRIP;
	game->texture_prop.width = RAY_STRIP;
	game->texture_prop.height = (game->half_height)
		+ ((int)game->wall_prop.projected_height / 2);
	if (game->texture_prop.height > game->window_height)
		game->texture_prop.height = game->window_height;
}

void	wall_dimension(t_game *game, int col)
{
	game->wall_prop.ray_distance = game->rays[col].xy.hypo
		* cos(game->rays[col].xy.angle - game->player.xy.angle);
	game->wall_prop.projected_height
		= (TILE_SIZE / game->wall_prop.ray_distance)
		* game->wall_prop.projected_wall;
}

void	texture_xy(t_game *game, int col, int line)
{
	if (game->rays[col].hit_vertical)
		game->wall_prop.x_color = (int)game->rays[col].xy.y % (TILE_SIZE);
	else
		game->wall_prop.x_color = (int)game->rays[col].xy.x % (TILE_SIZE);
	game->wall_prop.dist_from_top = line
		+ ((int)game->wall_prop.projected_height / 2) - (game->half_height);
	game->wall_prop.y_color = game->wall_prop.dist_from_top
		* ((float)TILE_SIZE / (int)game->wall_prop.projected_height);
}

void	draw_walls(t_game *game)
{
	register int		col;
	register int		line;
	t_image				current_img;

	col = 0;
	while (col < game->ray_num)
	{
		wall_dimension(game, col);
		game->zbuffer[col] = game->wall_prop.ray_distance;
		texture_prop(game, col);
		current_img = texture_id(game, col);
		line = game->texture_prop.y_offset;
		while (line < game->texture_prop.height)
		{
			texture_xy(game, col, line);
			draw_px(game->img, col, line,
				put_shade(get_color(current_img,
						game->wall_prop.x_color,
						game->wall_prop.y_color),
					game->rays[col].xy.hypo));
			line++;
		}
		col++;
	}
}
