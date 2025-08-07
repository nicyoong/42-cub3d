/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:05:02 by tching            #+#    #+#             */
/*   Updated: 2024/06/05 18:27:44 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strlcpy() function copies up to dstsize - 1 characters 
 *				from the string src to dst, NUL-terminating the result if dstsize
 *				is not 0. If the src and dst strings overlap, the behavior is
 *				undefined.
 * @param *dst	A pointer to the destination buffer where the C string is copied.
 * @param *src	A pointer to the source C string that will be copied.
 * @param dstsize The size of the destination buffer.
 * @return		The ft_strlcpy() returns return the total length of the string
 *				they tried to create.For ft_strlcpy() that means the length of
 *				src. If the return value is >= dstsize, the output string has
 *				been truncated. It is the caller's responsibility to handle this.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dstsize > 0)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}
