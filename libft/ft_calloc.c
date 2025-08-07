/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:46:21 by tching            #+#    #+#             */
/*   Updated: 2024/06/15 00:18:43 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_calloc() function contiguously allocates enough space for
 *				count objects that are size bytes of memory each and returns a
 *				pointer to the allocated memory. The allocated memory is filled
 *				with bytes of value zero.
 * @param count	The number of elements to allocate.
 * @param size	The size of each element.
 * @return		If the ft_calloc() function successful, it returns a pointer to
 *				the allocated memory, else if an error occurs or count is zero,
 *				return NULL.
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (count && size && count > UINT_MAX / size)
		return (NULL);
	c = malloc(count * size);
	if (!c)
		return (NULL);
	else
		ft_memset(c, 0, (count * size));
	return (c);
}
