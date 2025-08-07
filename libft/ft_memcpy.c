/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:44:52 by tching            #+#    #+#             */
/*   Updated: 2024/06/06 17:03:21 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The memcpy() function copies n bytes from memory area src to 
 *				memory area dst.  If dst and src overlap, behavior is undefined.
 * @param *dst	A pointer to the dst where the content is to be copied. 
 * @param *src	A pointer to the src from which the content is copied.
 * @param n		The no. of bytes to be copy from the src to the dst.
 * @return		The memcpy() function returns the original value of dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}
