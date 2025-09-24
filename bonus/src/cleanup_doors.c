#include "../inc/cub3D.h"

// Destroy one t_image safely (guard against NULLs)
static void destroy_image_safe(void *mlx, t_image *img)
{
	if (img && img->img) {
		mlx_destroy_image(mlx, img->img);
		img->img = NULL;
		img->buffer = NULL;
	}
}

// Free all door animation frames and the door array
void cleanup_doors(t_game *game)
{
	if (!game) return;
	if (!game->doors) return;

	// Each door has door->anim.frames [0..frame_count-1]
	for (int i = 0; i < game->door_count; i++) {
		t_door *d = &game->doors[i];
		if (d->anim.frames) {
			for (int f = 0; f < d->anim.frame_count; f++) {
				destroy_image_safe(game->mlx, &d->anim.frames[f]);
			}
			free(d->anim.frames);
			d->anim.frames = NULL;
			d->anim.frame_count = 0;
			d->anim.current = 0;
			d->anim.timer = 0.0;
		}
	}

	free(game->doors);
	game->doors = NULL;
	game->door_count = 0;
}

// Free zbuffer (depth buffer)
void cleanup_zbuffer(t_game *game)
{
	if (!game) return;
	if (game->zbuffer) {
		free(game->zbuffer);
		game->zbuffer = NULL;
	}
}
