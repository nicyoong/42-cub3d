/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:15:20 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 18:58:37 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	load_door_anim(t_game *game, t_door *door)
{
	int	frames;

	frames = 4;
	door->anim.frames = malloc(sizeof(t_image) * frames);
	if (!door->anim.frames)
		error("Door frames alloc failed", game);
	door->anim.frame_count = frames;
	door->anim.current = 0;
	door->anim.timer = 0.0;
	if (set_sprite(&door->anim.frames[0],
			game->mlx, "./assets/door_close.XPM")
		|| set_sprite(&door->anim.frames[1],
			game->mlx, "./assets/door_open1.XPM")
		|| set_sprite(&door->anim.frames[2],
			game->mlx, "./assets/door_open2.XPM")
		|| set_sprite(&door->anim.frames[3],
			game->mlx, "./assets/door_openfull.XPM"))
		error("Could not load door frames", game);
}



void	draw_doors_as_sprites(t_game *game)
{
	int		i;
	t_door	*d;
	t_image	frame;
	double	world_x;
	double	world_y;

	i = 0;
	while (i < game->door_count)
	{
		d = &game->doors[i];
		frame = d->anim.frames[d->anim.current];
		world_x = (d->x + 0.5) * TILE_SIZE;
		world_y = (d->y + 0.5) * TILE_SIZE;
		draw_door_sprite(game, frame, world_x, world_y);
		i++;
	}
}

t_door	*find_door(t_game *game, int map_x, int map_y)
{
	int	i;

	i = 0;
	while (i < game->door_count)
	{
		if (game->doors[i].x == map_x && game->doors[i].y == map_y)
			return (&game->doors[i]);
		i++;
	}
	return (NULL);
}

void	toggle_door(t_game *game)
{
	double	px;
	double	py;
	int		front_x;
	int		front_y;
	t_door	*door;

	px = game->player.xy.x / TILE_SIZE;
	py = game->player.xy.y / TILE_SIZE;
	front_x = (int)(px + cos(game->player.xy.angle) * DOOR_INTERACT_DIST);
	front_y = (int)(py + sin(game->player.xy.angle) * DOOR_INTERACT_DIST);
	if (front_x < 0 || front_y < 0
		|| front_y >= (int)count_vectors((void**)game->params.map)
		|| front_x >= (int)ft_strlen(game->params.map[front_y]))
		return ;
	if (game->params.map[front_y][front_x] == DOOR_TILE)
	{
		door = find_door(game, front_x, front_y);
		if (!door)
			return ;
		if (door->state <= DOOR_MIN)
			door->opening = 1;
		else if (door->state >= DOOR_MAX)
			door->opening = -1;
	}
}
