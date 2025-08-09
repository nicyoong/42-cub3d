/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:42:03 by tching            #+#    #+#             */
/*   Updated: 2025/08/10 01:49:04 by tching           ###   ########.fr       */
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
# include <../../libft/libft.h>
# include <../../mlx/mlx.h>

# define WINDOW_HEIGHT	720
# define WINDOW_WIDTH	128
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
	t_img		*img;
	uint32_t	*buffer;
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
	float	hit;
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
	char		*map;
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

#endif
