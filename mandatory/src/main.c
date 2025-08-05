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
	game->params.texture = ft_calloc(sizeof(char *), 4);
	if (!game->params.texture)
		//
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_cubed(&game);
	load_map(&game, argc, argv[argc - 1]);
	//map validation
	start_cubed(&game);
	return (0);
}
