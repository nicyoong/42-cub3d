#include "../inc/cub3D.h"

int	get_map(char *file, t_game *game)
{
	int		lines;
	int		chars;

	game->params.map = ft_split(file, '\n');
	if (!game->params.map)
		error("Failed map malloc", game);
	lines = 0;
	chars = 0;
	while (game->params.map[lines])
		chars += ft_strlen(game->params.map[lines++]);
	return ((chars + lines) - 1);
}

int	get_env_color(char *file, int identifier, t_game *game)
{
	int		i;
	int		n;
	char	*color;

	i = 1;
	while (ft_isspace(file[i]) && file[i] && file[i] != '\n')
		i++;
	if ((i - 1) == 0)
		error("Wrong identifier", game);
	n = 0;
	if (game->params.rgb[identifier])
		error("Duplicate identifier", game);
	while (file[n] != '\n' && file[n])
		n++;
	color = ft_substr(file + 1, 0, n);
	if (!color)
		error("Failed color malloc", game);
	game->params.rgb[identifier] = ft_split(color, ',');
	free_null((void *)&color);
	if (!game->params.rgb[identifier])
		error("Failed rgb malloc", game);
	return (n);
}

int	get_texture(char *file, int identifier, t_game *game)
{
	int	i;
	int	n;

	i = 2;
	while (ft_isspace(file[i]) && file[i] && file[i] != '\n')
		i++;
	if ((i - 2) == 0)
		error("Wrong identifier", game);
	n = 0;
	if (game->params.texture[identifier])
		error("Duplicate Identifier", game);
	while (file[n] != '\n' && file[n])
		n++;
	game->params.texture[identifier] = ft_substr(file + 3, 0, n - 3);
	if (!game->params.texture[identifier])
		error("Failed texture malloc", game);
	return (n);
}


