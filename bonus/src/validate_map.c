#include "cub3D.h"

void	empty_row(t_game *game)
{
	int	i;
	int	bl;
	int	lines_qtd;

	i = -1;
	bl = 0;
	lines_qtd = count_vectors((void **)game->params.map);
	while (game->map_cub[++i])
	{
		if (game->map_cub[i] == '\n')
		{
			bl++;
			if (game->map_cub[i + 1] == '\n' && bl < lines_qtd)
				error("Empty row on map", game);
		}
	}
}

int	sides_closed(char **map)
{
	if (ft_strrchr(*map, '1') < ft_strrchr(*map, '0'))
		return (0);
	if (ft_strchr(*map, '1') > ft_strchr(*map, '0') && ft_strchr(*map, '0'))
		return (0);
	return (1);
}

int	row_validate(char **map, t_map_validation v)
{
	if (!sides_closed(map + v.line_num))
		return (EXIT_FAILURE);
	if (v.line_num)
		v.column_limit[TOP_LINE] = ft_strlen(map[v.line_num - 1]) - 1;
	if (v.line_num < v.total_lines - 1)
		v.column_limit[BOTTOM_LINE] = ft_strlen(map[v.line_num + 1]) - 1;
	while (map[v.line_num][v.column])
	{
		if (!ft_strchr("0NEWSD", map[v.line_num][v.column]))
		{
			if (map[v.line_num][v.column] != '1' && v.is_closed_behind)
				return (EXIT_FAILURE);
			v.is_closed_behind = 0;
		}
		else
		{
			if (!surrounded(map, v))
				return (EXIT_FAILURE);
			v.is_closed_behind = 1;
		}
		v.column++;
	}
	return (EXIT_SUCCESS);
}

int	surrounded(char **map, t_map_validation v)
{
	if (!v.line_num || v.line_num == v.total_lines - 1)
		return (0);
	if (map[v.line_num][v.column - 1] != '1' && !v.is_closed_behind)
		return (0);
	if (v.line_num)
		if ((v.column >= v.column_limit[TOP_LINE] || \
			(map[v.line_num - 1][v.column - 1] == ' ') || \
			(map[v.line_num - 1][v.column] == ' ')))
			return (0);
	if (v.line_num < v.total_lines - 1)
		if ((v.column >= v.column_limit[BOTTOM_LINE] || \
			(map[v.line_num + 1][v.column - 1] == ' ') || \
			(map[v.line_num + 1][v.column] == ' ')))
			return (0);
	return (1);
}

void	map_validate(t_game *game)
{
	t_map_validation	v;

	resize_row(game);
	resize_column(game);
	empty_row(game);
	ft_bzero(v.column_limit, sizeof(int) * 2);
	v.total_lines = count_vectors((void **)game->params.map);
	v.line_num = -1;
	v.column = 0;
	v.is_closed_behind = 0;
	while (++v.line_num < v.total_lines)
		if (row_validate(game->params.map, v))
			error("No surrounding walls", game);
	game->minimap_width = get_max_ls(game->params.map) * TILE_SIZE;
	game->minimap_height = count_vectors((void **)game->params.map) * \
		TILE_SIZE;
}
