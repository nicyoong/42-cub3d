

#include "cub3D.h"

void	free_game(t_game *game)
{
	if (game->file != INPUT_ERROR)
		free_null((void *)&game->file);
	free_null((void *)&game->rays);
}

void	cleanup_game(t_game *game)
{
	if (game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	cleanup_sprites(game->wall_texture, game->mlx, TEXTURES_NUM);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free_null((void *)&game->mlx);
	}
}

void	exit_game(t_game *game)
{
	free_matrix((void **)game->params.map, 0);
	free_matrix((void **)game->params.texture, 4);
	free_matrix((void **)game->params.rgb[0], 0);
	free_matrix((void **)game->params.rgb[1], 0);
	cleanup_game(game);
	free_game(game);
	exit(errno);
}

int	close_window(t_game *game)
{
	printf("Closed window.\n");
	exit_game(game);
	return (0);
}


void	cleanup_sprites(t_image *images, void *mlx, int x)
{
	int		i;

	i = 0;
	while (i < x)
	{
		if (images[i].img)
			mlx_destroy_image(mlx, images[i].img);
		i++;
	}
}
