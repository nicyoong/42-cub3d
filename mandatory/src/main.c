/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 22:06:05 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 22:12:15 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_cubed(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	ft_bzero(&game->params, sizeof(t_params));
	ft_bzero(&game->player, sizeof(t_player));
	game->window_height = WINDOW_HEIGHT;
	game->window_width = WINDOW_WIDTH;
	game->half_height = WINDOW_HEIGHT / 2;
	game->half_width = WINDOW_WIDTH / 2;
	game->params.texture = ft_calloc(sizeof(char *), 4);
	game->player.move_speed = 4;
	game->player.rotate_speed = ROTATE_SPEED_2;
	game->wall_prop.projected_wall = game->half_width / tan(FOV_ANGLE / 2);
	if (!game->params.texture)
		error("Failed cub3d init.", game);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_cubed(&game);
	load_map(&game, argc, argv[argc - 1]);
	set_params(&game);
	start_cubed(&game);
	return (0);
}
