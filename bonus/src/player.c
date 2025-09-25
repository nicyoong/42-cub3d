#include "../inc/cub3D.h"

// Only for raycasting (walls)
// Doors are not walls for rendering – they’re drawn separately as sprites
int has_wall_for_raycast(t_game *game, double x, double y)
{
    int col = (int)floor(x / TILE_SIZE);
    int row = (int)floor(y / TILE_SIZE);

    if (row < 0 || row >= (int)count_vectors((void**)game->params.map))
        return 1;
    if (col < 0 || col >= (int)ft_strlen(game->params.map[row]))
        return 1;

    char tile = game->params.map[row][col];
    return (tile == '1');  // stop rays only on walls
}

// Only for player/collision logic
int is_blocking_tile(t_game *game, int col, int row)
{
    if (row < 0 || row >= (int)count_vectors((void**)game->params.map))
        return 1;
    if (col < 0 || col >= (int)ft_strlen(game->params.map[row]))
        return 1;

    char tile = game->params.map[row][col];
    if (tile == '1')
        return 1;
    if (tile == DOOR_TILE) {
        // check door state
        for (int i = 0; i < game->door_count; i++) {
            if (game->doors[i].x == col && game->doors[i].y == row) {
                return (game->doors[i].state < DOOR_MAX); // still closed
            }
        }
        return 1; // unknown door? block
    }
    return 0;
}

int	collide_diagonal(t_game *game, double to_x, double to_y)
{
	double	x_diff = to_x - game->player.xy.x;
	double	y_diff = to_y - game->player.xy.y;

	if (fabs(x_diff) <= TILE_SIZE && fabs(y_diff) <= TILE_SIZE)
	{
		// Check side tiles with is_blocking_tile()
		int col_x = (int)((to_x - x_diff) / TILE_SIZE);
		int row_x = (int)(to_y / TILE_SIZE);
		if (is_blocking_tile(game, col_x, row_x))
			return 1;

		int col_y = (int)(to_x / TILE_SIZE);
		int row_y = (int)((to_y - y_diff) / TILE_SIZE);
		if (is_blocking_tile(game, col_y, row_y))
			return 1;
	}
	return 0;
}

void	calculate_next_step(t_game *game, int move_step, int side_move)
{
	double	to_x;
	double	to_y;
	double	angle;
	int		margin_x;
	int		margin_y;

	angle = game->player.xy.angle;
	to_x = (cos(angle) * move_step) + (cos(angle + HALF_PI) * side_move);
	to_y = (sin(angle) * move_step) + (sin(angle + HALF_PI) * side_move);
	margin_x = 16;
	margin_y = 16;
	if (to_x < 0)
		margin_x = -16;
	if (to_y < 0)
		margin_y = -16;
	to_x += game->player.xy.x;
	to_y += game->player.xy.y;
	if (!is_blocking_tile(game, to_x + margin_x, to_y + margin_y) && \
		!collide_diagonal(game, to_x + margin_x, to_y + margin_y))
	{
		game->player.xy.x = to_x;
		game->player.xy.y = to_y;
	}
}

void	bound_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
		*angle = TWO_PI + *angle;
}

void	player_movement(t_game *game)
{
	int		move;
	int		side;

	if (game->player.move_direction)
	{
		game->player.xy.angle += game->player.move_direction * game->player.rotate_speed;
		bound_angle(&game->player.xy.angle);
	}
	if (game->player.side_direction || game->player.walk_direction)
	{
		move = game->player.walk_direction * game->player.move_speed;
		side = game->player.side_direction * game->player.move_speed;
		if (game->player.side_direction && game->player.walk_direction)
		{
			move /= 2;
			side /= 2;
		}
		calculate_next_step(game, move, side);
	}
}




