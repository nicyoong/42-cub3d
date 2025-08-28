#include "cub3D.h"

uint32_t	put_shade(uint32_t color, double scale)
{
	int		r;
	int		g;
	int		b;

	if (color == TRANSPARENCY || scale <= SHADE_NUMERATOR)
		return (color);
	scale = SHADE_NUMERATOR / scale;
	r = ((color >> 16) & 0xFF) * scale;
	g = ((color >> 8) & 0xFF) * scale;
	b = (color & 0xFF) * scale;
	return ((r << 16) | (g << 8) | b);
}

void	draw_px(t_image image, int x, int y, uint32_t color)
{
	if (color != TRANSPARENCY)
		*(image.buffer + (x + y * image.img->size_line)) = color;
}

uint32_t	get_color(t_image image, int x, int y)
{
	return (*(image.buffer + (x + y * image.img->size_line)));
}

void	rectangle(t_image image, t_img_prop *prop)
{
	int		i;
	int		j;

	j = 0;
	while (j < prop->height)
	{
		i = 0;
		while (i < prop->width)
		{
			draw_px(image, \
				prop->x_offset + i, \
				prop->y_offset + j, \
				prop->color \
			);
			i++;
		}
		j++;
	}
}

void	draw_cf(t_game *game)
{
	game->texture_prop.color = game->params.env[CEILING];
	game->texture_prop.x_offset = 0;
	game->texture_prop.y_offset = 0;
	game->texture_prop.height = game->half_height;
	game->texture_prop.width = game->window_width;
	rectangle(game->img, &game->texture_prop);
	game->texture_prop.color = game->params.env[FLOOR];
	game->texture_prop.x_offset = 0;
	game->texture_prop.y_offset = game->half_height;
	game->texture_prop.height = game->half_height;
	game->texture_prop.width = game->window_width;
	rectangle(game->img, &game->texture_prop);
}
