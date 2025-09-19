#include "../inc/cub3D.h"

int	main(int argc, char **argv)
{
	t_game	game;

	init_cubed(&game);
	open_file(&game, argc, argv[argc - 1]);
	set_params(&game);
	validate_file(&game);
	setup_game(&game);
	start_cubed(&game);
	return (0);
}

void	init_cubed(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	ft_bzero(&game->params, sizeof(t_params));
	ft_bzero(&game->player, sizeof(t_player));
	game->window_width = WINDOW_WIDTH;
	game->window_height = WINDOW_HEIGHT;
	game->half_width = game->window_width / 2;
	game->half_height = game->window_height / 2;
	game->wall_prop.projected_wall = game->half_width / tan(FOV_ANGLE / 2);
	game->player.rotate_speed = ROTATION_SPEED;
	game->player.move_speed = MOVEMENT_SPEED;
	game->params.texture = ft_calloc(sizeof(char *), 4);
	if (!game->params.texture)
		error("Failed texture calloc", game);
}

int	init_graphics(t_game *game)
{
	player_movement(game);
	cast_all_rays(game);
	draw_cf(game);
	draw_walls(game);
	mlx_do_sync(game->mlx);
	mlx_put_image_to_window(game->mlx, game->window, game->img.img, 0, 0);
	return (0);
}

void	start_cubed(t_game *game)
{
	mlx_hook(game->window, 2, 1, press_key, game);
	mlx_hook(game->window, 3, 2, release_key, game);
	mlx_hook(game->window, 17, 0, close_window, game);
	mlx_hook(game->window, 6, 1L<<6, mouse_move, game);
	mlx_loop_hook(game->mlx, init_graphics, game);
	mlx_loop(game->mlx);
}

void	error(char *msg, t_game *game)
{
	printf("Error\n%s.\n%s\n", msg, strerror(errno));
	free_matrix((void **)game->params.map, 0);
	free_matrix((void **)game->params.texture, 4);
	free_matrix((void **)game->params.rgb[0], 0);
	free_matrix((void **)game->params.rgb[1], 0);
	cleanup_game(game);
	free_game(game);
	exit(errno);
}
