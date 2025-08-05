/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 20:42:03 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 20:50:33 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# define WINDOW_HEIGHT	720
# define WINDOW_WIDTH	128

typedef struct
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
