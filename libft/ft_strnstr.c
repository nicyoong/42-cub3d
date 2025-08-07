/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:39:18 by tching            #+#    #+#             */
/*   Updated: 2024/06/14 19:06:55 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strnstr() function locates the first occurrence of the 
 *				null-terminated string needle in the string haystack, where not
 *				more than len characters are searched.  Characters that appear
 *				after a `\0' character are not searched. Since the ft_strnstr()
 *				function is a FreeBSD specific API, it should only be used when
 *				portability is not a concern.
 * @param *haystack The main string to be searched.
 * @param *needle	The sub-string to find within *haystack.
 * @param len		The maximum number of characters to search in the haystack.
 * @return		If needle is an empty string, haystack is returned; if needle 
 *				occurs nowhere in haystack, NULL is returned; otherwise a 
 *				pointer to the first character of the first occurrence of 
 *				needle is returned.
 */
char	*ft_strnstr(char const *haystack, char const *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!haystack && len == '\0')
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		while (haystack [i + j] && haystack [i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
