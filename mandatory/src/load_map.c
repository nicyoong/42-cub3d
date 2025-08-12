/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 21:39:41 by tching            #+#    #+#             */
/*   Updated: 2025/08/05 21:50:29 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(int argc, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (argc != 2)
		printf("Error\nInvalid no. of arguments. %s", ENOENT);
	else if (fd < 0)
		printf("Error\nCannot open file. %s", ENOENT);
	else if (ft_strcmp(".cub", argv + (ft_strlen(argv) - 4)))
		printf("Error\nInvalid file extension.");
	else
		return (fd);
	if (fd != -1)
		close (fd);
	return (-1);
}

void	load_map(t_game *game, int argc, char *argv)
{
	char	buffer[501];
	char	*swap;
	ssize_t	size;
	int	fd;

	fd = check_file(argc, argv);
	if (fd = -1)
		exit_game(game);
	game->file = ft_calloc(sizeof(char), 1);
	size = read(fd, buffer, 500);
	while (size > 0)
	{
		buffer[size] = 0;
		swap = ft_strdup(game->file);
		free(game->file);
		game->file = ft_strjoin(swap, buffer);
		free (swap);
		size = read(fd, buffer, 500);
	}
	close (fd);
	if (*game->file == '\0')
		error("File content is empty.", game);
}

