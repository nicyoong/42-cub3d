#include "cub3D.h"

void	reverse_matrix(char **ptr)
{
	int	i;

	i = 0;
	free(ptr[i]);
	while (ptr[i])
	{
		ptr[i] = ptr[i + 1];
		i++;
	}
}

int	walls_and_spaces(char *map_line)
{
	int		i;

	i = 0;
	while (map_line[i])
		if (ft_strchr("0NEWS", map_line[i++]))
			return (0);
	return (1);
}

int	is_invalid_tile(char **map, t_resize_validation v)
{
	if (map[v.line][v.counter] == '0' || \
		(!v.counter || ft_strchr("0NEWS", map[v.line][v.counter - 1])))
		return (0);
	if (v.line)
		if (v.counter <= v.column_limit[TOP_LINE])
			if (ft_strchr("0NEWS", map[v.line - 1][v.counter]) || \
				ft_strchr("0NEWS", map[v.line - 1][v.counter - 1]))
				return (0);
	if (v.line < v.total_lines)
		if (v.counter <= v.column_limit[BOTTOM_LINE])
			if (ft_strchr("0NEWS", map[v.line + 1][v.counter]) || \
				ft_strchr("0NEWS", map[v.line + 1][v.counter - 1]))
				return (0);
	return (1);
}

void	resize_row(t_game *game)
{
	int		line;
	int		c;

	line = 0;
	c = 0;
	while (walls_and_spaces(game->params.map[line]))
		line++;
	while (c < line - 1)
	{
		reverse_matrix(game->params.map);
		c++;
	}
	line = count_vectors((void **)game->params.map) - 1;
	c = line;
	while (walls_and_spaces(game->params.map[line]))
		line--;
	while (c > line + 1)
		reverse_matrix(game->params.map + c--);
}

void	resize_column(t_game *game)
{
	t_resize_validation	v;
	char			*tmp;

	v.line = -1;
	v.total_lines = count_vectors((void **)game->params.map) - 1;
	while (game->params.map[++v.line])
	{
		v.counter = ft_strlen(game->params.map[v.line]) - 1;
		if (v.line)
			v.column_limit[TOP_LINE] = ft_strlen(game->params.map[v.line - 1]) - 1;
		if (v.line < v.total_lines)
			v.column_limit[BOTTOM_LINE] = ft_strlen(game->params.map[v.line + 1]) - 1;
		while (is_invalid_tile(game->params.map, v))
			v.counter--;
		if (v.counter == ft_strlen(game->params.map[v.line]) - 1)
			continue ;
		tmp = ft_substr(game->params.map[v.line], 0, v.counter + 1);
		free_null((void *)&game->params.map[v.line]);
		game->params.map[v.line] = tmp;
	}
}



