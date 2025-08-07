/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:59:55 by tching            #+#    #+#             */
/*   Updated: 2024/06/14 13:52:10 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The memmove() function copies len bytes from string src to 
 *				string dst. The two strings may overlap; the copy is always
 *				done in a non-destructive manner.
 * @param *dst	A pointer to the dst where the content is to be moved. 
 * @param *src	A pointer to the src from which the content is moving from.
 * @param len	The no. of bytes to move from the src to the dst.
 * @return		The memmove() function returns the original value of dst.
 */
void	*ft_memmove(void *dst, void const *src, size_t len)
{
	size_t			i;

	if (!src && !dst)
		return (NULL);
	i = 0;
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((char *)dst)[i] = ((char *)src)[i];
		}
	}
	else
	{
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
}
