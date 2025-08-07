/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:22:40 by tching            #+#    #+#             */
/*   Updated: 2024/06/14 14:59:50 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strlcat() function appends string src to the end of dst.
 *				It will append at most dstsize - strlen(dst) - 1 characters.
 *				It will then NUL-terminate, unless dstsize is 0 or the original
 *				dst string was longer than dstsize (in practice this should not
 *				happen as it means that either dstsize is incorrect or that dst
 *				is not a proper string). If the src and dst strings overlap, 
 *				the behavior is undefined.
 * @param *dst	The destination string to which src is appended.
 * @param *src	The source string to append to dst.
 * @param dstsize The full size of the destination buffer.
 * @return		The ft_strlcat() returns return the total length of the string
 *				they tried to create. For ft_strlcat() that means the initial 
 *				length of dst plus the length of src.If the return value 
 *				is >= dstsize, the output string has been truncated. 
 *				It is the caller's responsibility to handle this.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		total_len;
	char const	*s;

	if ((!dst || !src) && !dstsize)
		return (ft_strlen(src));
	s = src;
	dst_len = 0;
	while (dst[dst_len] && dst_len < dstsize)
		dst_len++;
	if (dst_len < dstsize)
		total_len = dst_len + ft_strlen(s);
	else
		return (dstsize + ft_strlen(s));
	while (*s && (dst_len + 1) < dstsize)
	{
		dst[dst_len] = *s++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (total_len);
}
