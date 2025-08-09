/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:56:31 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 21:00:31 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int keycode, t_game *game)
{
	if (keycode == LEFT)
		game->player.move_direction = 0;
	else if (keycode == RIGHT)
		game->player.move_direction = 0;
	else if (keycode == 'a')
		game->player.side_direction = 0;
	else if (keycode == 's')
		game->player.side_direction = 0;
	else if (keycode == 'd')
		game->player.side_direction = 0;
	else if (keycode == 'w')
		game->player.side_direction = 0;
	else if (keycode == 'SHIFT')
		game->player.move_speed = 8;
	else if (keycode == 'ESC')
		exit_game(game);
	return (0);
}

int	keypress_game(int keycode, t_game *game)
{
	if (keycode == LEFT)
		game->player.move_direction = LEFT_TURN;
	else if (keycode == RIGHT)
		game->player.move_direction = RIGHT_TURN;
	else if (keycode == 'a')
		game->player.side_direction = MOVE_LEFT;
	else if (keycode == 's')
		game->player.side_direction = MOVE_DOWN;
	else if (keycode == 'd')
		game->player.side_direction = MOVE_RIGHT;
	else if (keycode == 'w')
		game->player.side_direction = MOVE_UP;
	else if (keycode == 'SHIFT')
		game->player.move_speed = 12;
	else if (keycode == 'ESC')
		exit_game(game);
	return (0);
}


