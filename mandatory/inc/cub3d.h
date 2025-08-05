/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:42:03 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 21:21:24 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <../../libs/libft/libft.h>

# define WINDOW_HEIGHT	720
# define WINDOW_WIDTH	128

# define LEFT	65361
# define RIGHT	65363
# define UP	65362
# define DOWN	65364
# define ESC	65307

# define INVALID_PTR	(void *)-1

enum	e_axis{
	x,
	y,
	z
};

enum	e_direction{
	NORTH,
	SOUTH,
	WEST,
	EAST
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
	uint32_t	color;
}	t_img_prop;

typedef struct s_axis
{
	double		x;
	double		y;
}	t_axis;

typedef struct s_player
{
	t_axis	xy;
	int	player_direction;
}	t_player;

typedef struct s_params
{
	char	**texture;
	char	**map;
	char	**color[2];
}	t_params;

typedef struct s_game
{
	int		window_height;
	int		window_width;
	char		*file;
	char		*map;
	t_xvar		*mlx;
	t_win_list	*window;
	t_player	player;
	t_image		img;
	t_params	params;
		
//to be expanded
}	t_game;

#endif
