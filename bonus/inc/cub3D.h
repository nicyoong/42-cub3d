#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include <stdbool.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include <fcntl.h>
# include <string.h>
# include <stdint.h>
# include <limits.h>

# define INPUT_ERROR				(void *)-1

# define MOVEMENT_SPEED			4
# define RAY_STRIP				1
# define TILE_SIZE				64
# define WINDOW_WIDTH		1280
# define WINDOW_HEIGHT		720
# define TEXTURES_NUM			4
# define FOV_ANGLE				1.0471975511965977461542144610932
# define ROTATION_SPEED 	0.03490658503988659153847381536977

# define HALF_PI				1.570796
# define PI						3.141592
# define PI_PLUS_HALF_PI		4.712388
# define TWO_PI					6.283185

# define TURN_RIGHT				1
# define TURN_LEFT				-1

# define WALK_LEFT				-1
# define WALK_UP				1
# define WALK_RIGHT				1
# define WALK_DOWN				-1

# define ESC					65307
# define SHIFT					65505
# define ARROW_LEFT				65361
# define ARROW_UP				65362
# define ARROW_RIGHT			65363
# define ARROW_DOWN				65364

# define TRANSPARENCY			0xFF000000
# define SHADE_NUMERATOR		600

enum e_level{
	HORIZONTAL,
	VERTICAL
};

enum e_axis{
	x,
	y
};

enum e_column_max{
	TOP_LINE,
	BOTTOM_LINE
};

enum e_env{
	CEILING,
	FLOOR
};

enum e_direction{
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
	uint32_t	color;
	int			height;
	int			width;
	int			x_offset;
	int			y_offset;
}	t_img_prop;

typedef struct s_axis
{
	double			x;
	double			y;
	double			angle;
	double			hypo;
}	t_axis;

typedef struct s_player
{
	t_axis		xy;
	double		rotate_speed;
	int			move_speed;
	int			move_direction;
	int			walk_direction;
	int			side_direction;
}	t_player;

typedef struct s_rays_prop
{
	float	x_int;
	float	y_int;
	float	x_step;
	float	y_step;
	bool	is_hit;
	float	hypo;
}	t_rays_prop;

typedef struct s_ray
{
	t_axis	xy;
	bool	hit_vertical;
	bool	ray_up;
	bool	ray_left;
}	t_ray;

typedef struct s_params
{
	char	**map;
	char	**texture;
	char	**rgb[2];
	int		env[2];
}	t_params;

typedef struct	s_door
{
	int		x;
	int		y;
	int		is_open;
	double	progress;
}	t_door;

typedef struct s_wall_prop
{
	float		projected_height;
	float		projected_wall;
	float		ray_distance;
	int			dist_from_top;
	u_int32_t	x_color;
	u_int32_t	y_color;
}	t_wall_prop;

typedef struct s_game
{
	t_xvar					*mlx;
	t_win_list				*window;
	int						window_width;
	int						window_height;
	int						minimap_height;
	int						minimap_width;
	long					half_height;
	long					half_width;
	long					ray_num;
	char					*file;
	char					*map_cub;
	t_ray					*rays;
	t_rays_prop				ray_prop[2];
	t_img_prop				texture_prop;
	t_wall_prop				wall_prop;
	t_player				player;
	t_params				params;
	t_image					img;
	t_image					wall_texture[TEXTURES_NUM];
}	t_game;

typedef struct s_resize_validation
{
	size_t	total_lines;
	size_t	line;
	size_t	counter;
	size_t	column_limit[2];
}	t_resize_validation;

typedef struct s_map_validation
{
	int		is_closed_behind;
	int		column_limit[2];
	int		column;
	size_t	line_num;
	size_t	total_lines;
}	t_map_validation;

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
int		close_window(t_game *game);
double  hypotenuse(double x, double y);

int     file_check(int argc,char *argv);
void    open_file(t_game *game, int argc, char *argv);

int get_map(char *file, t_game *game);
int get_env_color(char *file, int identifier, t_game *game);
int get_texture(char *file, int identifier, t_game *game);

void    set_window(t_game *game);
void    set_images(t_game *game);
int    set_sprite(t_image *image, void *mlx, char *path);
void    set_texture(t_game *game);
void    setup_game(t_game *game);
void	set_params(t_game *game);

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
void    vertical_cast(t_game *game, t_rays_prop *v, t_ray *ray);
void    horizontal_cast(t_game *game, t_rays_prop *h, t_ray *ray);
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
int surrounded(char **map, t_map_validation v);
int row_validate(char **map, t_map_validation v);
void    map_validate(t_game *game);

void    reverse_matrix(char **ptr);
int wall_and_space(char *map_line);
int is_invalid_tile(char **map, t_resize_validation v);
void    resize_row(t_game *game);
void    resize_column(t_game *game);

void    free_matrix(void **matix, size_t size);
size_t  count_vectors(void **matrix);
void    char_player_validate(t_game *game);
void    color_validate(t_game *game, int env);
void    validate_file(t_game *game);

#endif
