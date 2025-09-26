/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 18:15:20 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 18:15:21 by nyoong           ###   ########.fr       */
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

int	clampi(int v, int lo, int hi)
{
	if (v < lo)
		return (lo);
	if (v > hi)
		return (hi);
	return (v);
}

t_camera	make_camera(const t_game *game)
{
	t_camera	c;
	double		a;
	double		pa;

	a = game->player.xy.angle;
	pa = a + HALF_PI;
	c.dirX = cos(a);
	c.dirY = sin(a);
	c.planeX = cos(pa) * (FOV_ANGLE);
	c.planeY = sin(pa) * (FOV_ANGLE);
	return (c);
}

t_vec2d	sprite_delta(const t_game *game, double sx, double sy)
{
	t_vec2d	d;

	d.x = sx - game->player.xy.x;
	d.y = sy - game->player.xy.y;
	return (d);
}

double	inv_det(const t_camera *c)
{
	double	det;

	det = (c->planeX * c->dirY) - (c->dirX * c->planeY);
	if (fabs(det) < 1e-9)
		return (1e9);
	return (1.0 / det);
}

t_vec2d	camera_space(const t_vec2d *d, const t_camera *c, double invDet)
{
	t_vec2d	t;

	t.x = invDet * (c->dirY * d->x - c->dirX * d->y);
	t.y = invDet * (-c->planeY * d->x + c->planeX * d->y);
	return (t);
}

t_spriteproj	project_sprite(const t_game *game,
	const t_vec2d *t, t_image img)
{
	t_spriteproj	p;
	double			invy;
	int				baseh;

	invy = 1.0 / t->y;
	baseh = (int)(TILE_SIZE * invy * game->wall_prop.projected_wall);
	p.screenX = (int)(game->half_width * (1.0 + (t->x * invy)));
	p.height = baseh;
	if (p.height < 1)
		p.height = 1;
	p.width = (int)((double)p.height * img.img->width / img.img->height);
	if (p.width < 1)
		p.width = 1;
	return (p);
}

t_drawrect	draw_rect(const t_game *game, const t_spriteproj *p)
{
	t_drawrect	r;
	int			hh;

	hh = game->half_height;
	r.startY = clampi(-p->height / 2 + hh, 0, game->window_height - 1);
	r.endY = clampi(p->height / 2 + hh, 0, game->window_height - 1);
	r.startX = clampi(-p->width / 2 + p->screenX, 0, game->window_width - 1);
	r.endX = clampi(p->width / 2 + p->screenX, 0, game->window_width - 1);
	return (r);
}

int	tex_x_for_stripe(int stripe, const t_spriteproj *p, int texW)
{
	int	left;
	int	texx;

	left = -p->width / 2 + p->screenX;
	texx = (int)((stripe - left) * (double)texW / (double)p->width);
	return (clampi(texx, 0, texW - 1));
}

int	tex_y_for_y(int y, const t_game *game, const t_spriteproj *p, int texH)
{
	int	top;
	int	d;
	int	texy;

	top = -p->height / 2 + game->half_height;
	d = y - top;
	texy = (int)((double)d * (double)texH / (double)p->height);
	return (clampi(texy, 0, texH - 1));
}

void	draw_sprite_columns(t_game *game, t_image img,
	const t_spriteproj *p, const t_drawrect *r, double depth)
{
	int			stripe;
	int			texx;
	int			y;
	int			texy;
	uint32_t	color;

	stripe = r->startX;
	while (stripe <= r->endX)
	{
		if (stripe >= 0 && stripe < game->window_width)
		{
			if (depth < game->zbuffer[stripe])
			{
				texx = tex_x_for_stripe(stripe, p, img.img->width);
				y = r->startY;
				while (y <= r->endY)
				{
					texy = tex_y_for_y(y, game, p, img.img->height);
					color = get_color(img, texx, texy);
					if ((color & 0xFF000000) != TRANSPARENCY)
						draw_px(game->img, stripe, y, color);
					y++;
				}
			}
		}
		stripe++;
	}
}

void	draw_door_sprite(t_game *game, t_image img, double sx, double sy)
{
	t_camera		cam;
	t_vec2d			delta;
	double			inv;
	t_vec2d			t;
	t_spriteproj	proj;
	t_drawrect		rect;

	cam = make_camera(game);
	delta = sprite_delta(game, sx, sy);
	inv = inv_det(&cam);
	t = camera_space(&delta, &cam, inv);
	if (t.y <= 0.0001)
		return ;
	proj = project_sprite(game, &t, img);
	rect = draw_rect(game, &proj);
	draw_sprite_columns(game, img, &proj, &rect, t.y);
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
