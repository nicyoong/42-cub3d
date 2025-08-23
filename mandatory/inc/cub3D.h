/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 20:50:09 by tching            #+#    #+#             */
/*   Updated: 2025/08/20 20:50:12 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <libft.h>
# include <mlx.h>
# include <mlx_int.h>

# define WINDOW_HEIGHT	720
# define WINDOW_WIDTH	1280
# define TILE_SIZE		64

# define LEFT	65361
# define RIGHT	65363
# define UP	65362
# define DOWN	65364
# define ESC	65307
# define SHIFT	65505

# define RIGHT_TURN	1
# define LEFT_TURN -1

# define MOVE_LEFT -1
# define MOVE_RIGHT 1
# define MOVE_UP	1
# define MOVE_DOWN	-1

# define TRANSPARENT	0xFF000000
# define SHADE_NUM		600
# define TEXTURE_NUM	4
# define RAY_STRIP		1

# define INVALID_PTR	(void *)-1
# define PI				3.14159265359
# define HALF_PI		1.57079632679
# define DOUBLE_PI		6.28318530718
# define PI_AND_HALF_PI		4.71238898038

# define FOV_ANGLE			1.0471975511965977461542144610932 //(60.0 * PI / 180.0)
# define ROTATE_SPEED_1 	0.01745329251994329576923690768489
# define ROTATE_SPEED_2 	0.03490658503988659153847381536977
# define ROTATE_SPEED_3 	0.06981317007977318307694763073954
# define ROTATE_SPEED_4		0.10471975511965977461542144610932

enum	e_axis{
	x,
	y
};

enum	e_level{
	HORIZONTAL,
	VERTICAL
};

enum	e_env{
	CEILING,
	FLOOR
};

enum	e_column{
	TOP_LINE,
	BOTTOM_LINE,
};

enum	e_direction{
	NO,
	SO,
	WE,
	EA
};

typedef struct s_image
{
	uint32_t	*buffer;
	t_img		*img;
}	t_image;

typedef struct s_img_prop
{
	int		height;
	int		width;
	int		x_offset;
	int		y_offset;
	uint32_t	color;
}	t_img_prop;

typedef struct s_wall_prop
{
	u_int32_t	x_color;
	u_int32_t	y_color;
	int			dist_from_top;
	float		projected_height;
	float		projected_wall;
	float		ray_distance;
}	t_wall_prop;

typedef struct s_axis
{
	double		x;
	double		y;
	double		angle;
	double		hypotenus;
}	t_axis;

typedef struct s_player
{
	t_axis	xy;
	double	rotate_speed;
	int	player_direction;
	int	move_speed;
	int	move_direction;
	int walk_direction;
	int	side_direction;
}	t_player;

typedef struct s_params
{
	char	**texture;
	char	**map;
	char	**color[2];
	int	env[2];
}	t_params;

typedef struct s_ray_prop
{
	float	hypotenuse;
	bool	hit;
	float	x_int;
	float	y_int;
	float	x_step;
	float	y_step;
}	t_ray_prop;

typedef struct s_ray
{
	t_axis	xy;
	bool	ray_up;
	bool	ray_left;
	bool	hit_vertical;
}	t_ray;

typedef struct s_validation
{
	int		closed;
	int		col_limit[2];
	int		col;
    int     row;
	size_t	row_num;
	size_t	total_row;
    size_t  counter;
}	t_validation;

typedef struct s_game
{
	int		window_height;
	int		window_width;
	int		minimap_height;
	int		minimap_width;
	long	half_height;
	long	half_width;
	long	ray_nums;
	char		*file;
	char		*map_cub;
	t_xvar		*mlx;
	t_win_list	*window;
	t_player	player;
	t_image		img;
	t_image		wall_texture[TEXTURE_NUM];
	t_params	params;
	t_img_prop	texture_properties;
	t_wall_prop	wall_prop;
	t_ray		*rays;
	t_ray_prop	ray_prop[2];
}	t_game;

void    init_cubed(t_game *game);
int     init_graphics(t_game *game);
void    start_cubed(t_game *game);

void    error(char *message, t_game *game);
void    exit_game(t_game *game);
void    free_null(void **ptr);
void    cleanup_sprites(t_image *image, void *mlx, int x);
void    cleanup_game(t_game *game);
void    free_game(t_game *game);
void    exit_game(t_game *game);
int close_window(t_game *game);
double  hypotenuse(double x, double y);

int     file_check(int argc,char *argv);
void    open_file(t_game *game, int argc, char **argv);

int get_map(char *file, t_game *game);
int get_env_color(char *file, int identifier, t_game *game);
int get_texture(char *file, int identifier, t_game *game);

void    set_window(t_game *game);
void    set_images(t_game *game);
void    set_sprite(t_image *image, void *mlx, char *path);
void    set_texture(t_game *game);
void    setup_game(t_game *game);

void    player_rotate_angle(t_game *game, char c);
void    set_player(t_game *game);
void    set_rays(t_game *game);
size_t  get_max_ls(char **map);

int press_key(int keycode, t_game *game);
int release_key(int keycode, t_game *game);

int has_wall(t_game *game, double x, double y);
int collide_diagonal(t_game *game, double to_x, double to_y);
void    calculate_next_step(t_game *game, int move, int side_move);
void    bound_angle(double *angle);
void    player_movement(t_game *game);

void    contruct_ray(t_ray *ray);
void    vertical_cast(t_game *game, t_ray_prop *v, t_ray *ray);
void    horizontal_cast(t_game *game, t_ray_prop *h, t_ray *ray);
void    calculate_distance(t_game *game, t_ray *ray);
void    raycast(t_game *game, t_ray *ray);
void    cast_all_rays(t_game *game);

t_image texture_id(t_game *game, int col);
void    texture_prop(t_game *game, int col);
void    wall_dimension(t_game *game, int col);
void    texture_xy(t_game *game, int col, int row);
void    draw_walls(t_game *game);

uint32_t    put_shade(uint32_t color, double scale);
uint32_t    get_color(t_image image, int x, int y);
void    draw_px(t_image image, int x, int y, uint32_t color);
void    rectangle(t_image image, t_img_prop *prop);
void    draw_cf(t_game *game);

void    empty_row(t_game *game);
int sides_closed(char **map);
int surrounded(char **map, t_validation v);
int row_validate(char **map, t_validation v);
void    map_validate(t_game *game);

void    reverse_matrix(char **ptr);
int wall_and_space(char *map_line);
int is_invalid_tile(char **map, t_validation v);
void    resize_row(t_game *game);
void    resize_col(t_game *game);

void    free_matrix(void **matix, size_t size);
size_t  count_vector(void **matrix);
void    char_player_validate(t_game *game);
void    color_validate(t_game *game, int env);
void    validate_file(t_game *game);

#endif