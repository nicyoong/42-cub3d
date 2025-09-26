/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:18:50 by tching            #+#    #+#             */
/*   Updated: 2025/09/26 22:47:21 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	press_key(int keycode, t_game *game)
{
	if (keycode == ARROW_RIGHT)
		game->player.move_direction = TURN_RIGHT;
	else if (keycode == ARROW_LEFT)
		game->player.move_direction = TURN_LEFT;
	else if (keycode == 'a')
		game->player.side_direction = WALK_LEFT;
	else if (keycode == 'd')
		game->player.side_direction = WALK_RIGHT;
	else if (keycode == 's')
		game->player.walk_direction = WALK_DOWN;
	else if (keycode == 'w')
		game->player.walk_direction = WALK_UP;
	else if (keycode == ESC)
		exit_game(game);
	else if (keycode == SHIFT)
		game->player.move_speed = 16;
	return (0);
}

int	release_key(int keycode, t_game *game)
{
	if (keycode == ARROW_RIGHT)
		game->player.move_direction = 0;
	else if (keycode == ARROW_LEFT)
		game->player.move_direction = 0;
	else if (keycode == 'd')
		game->player.side_direction = 0;
	else if (keycode == 'a')
		game->player.side_direction = 0;
	else if (keycode == 's')
		game->player.walk_direction = 0;
	else if (keycode == 'w')
		game->player.walk_direction = 0;
	else if (keycode == SHIFT)
		game->player.move_speed = 8;
	return (0);
}
