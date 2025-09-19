
#include "cub3D.h"

double	hypotenuse(double x, double y)
{
	return (sqrt(x * x + y * y));
}

size_t	count_vectors(void **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

void	free_matrix(void **matrix, size_t size)
{
	size_t	i;

	i = -1;
	if (matrix != NULL)
	{
		if (size)
		{
			while (++i < size)
				free_null((void *)&matrix[i]);
		}
		else
			while (matrix[++i])
				free_null((void *)&matrix[i]);
		free_null((void *)&matrix);
	}
}
void	free_null(void **ptr)
{
	if (*ptr != NULL)
		free(*ptr);
	*ptr = NULL;
}