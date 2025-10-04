/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyoong <nyoong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 19:00:28 by nyoong            #+#    #+#             */
/*   Updated: 2025/09/26 19:00:29 by nyoong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	open_file(t_game *game, int argc, char *argv)
{
	char	*swap;
	char	buffer[1024];
	ssize_t	size;
	int		fd;

	fd = file_check(argc, argv);
	if (fd == -1)
		exit_game(game);
	game->file = ft_calloc(sizeof(char), 1);
	size = read(fd, buffer, 1023);
	while (size > 0)
	{
		buffer[size] = 0;
		swap = ft_strdup(game->file);
		free(game->file);
		game->file = ft_strjoin(swap, buffer);
		free(swap);
		size = read(fd, buffer, 1023);
	}
	close(fd);
	if (*game->file == '\0')
		error("It's an empty file", game);
}

int	file_check(int argc, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (argc != 2)
		printf("Error\nInvalid number of arguments. %s", strerror(errno));
	else if (fd < 0)
		printf("Error\nFile could not be open. %s", strerror(errno));
	else if (ft_strcmp(".cub", argv + (ft_strlen(argv) - 4)))
		printf("Error\nFile is not a .cub extension.");
	else
		return (fd);
	if (fd != -1)
		close(fd);
	return (-1);
}
