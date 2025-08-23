/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 19:07:18 by tching            #+#    #+#             */
/*   Updated: 2025/08/21 19:07:28 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int press_key(int keycode, t_game *game)
{
    if (keycode == RIGHT)
        game->player.move_direction = RIGHT_TURN;
    else if (keycode == LEFT)
        game->player.move_direction = LEFT_TURN;
    else if (keycode == 'a')
        game->player.move_direction = MOVE_LEFT;
    else if (keycode == 's')
        game->player.move_direction = MOVE_DOWN;
    else if (keycode == 'd')
        game->player.move_direction = MOVE_RIGHT;
    else if (keycode == 'w')
        game->player.move_direction = MOVE_UP;
    else if (keycode == ESC)
        exit_game(game);
    else if (keycode == SHIFT)
        game->player.move_direction = 16;
    return (0);    
}

int release_key(int keycode, t_game *game)
{
    if (keycode == RIGHT)
        game->player.move_direction = 0;
    else if (keycode == LEFT)
        game->player.move_direction = 0;
    else if (keycode == 'a')
        game->player.move_direction = 0;
    else if (keycode == 's')
        game->player.move_direction = 0;
    else if (keycode == 'd')
        game->player.move_direction = 0;
    else if (keycode == 'w')
        game->player.move_direction = 0;
    else if (keycode == SHIFT)
        game->player.move_direction = 8;
    return (0);
}
