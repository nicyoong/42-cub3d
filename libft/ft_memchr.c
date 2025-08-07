/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:21:17 by tching            #+#    #+#             */
/*   Updated: 2024/06/06 18:30:56 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The memchr() function locates the first occurrence of c 
 *				(converted to an unsigned char) in string s.
 * @param *s	A pointer to the string where the search is performed. 
 * @param c		The character to search for, passed as an int but converted to
 *				an unsigned char for comparison.
 * @param n		The no. of bytes to be analyzed in the string pointed to by *s.
 * @return		The memchr() function returns a pointer to the byte located, 
 *				or NULL if no such byte exists within n bytes.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sc;
	unsigned char	cc;
	size_t			i;

	sc = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (sc[i] == cc)
			return ((void *)&sc[i]);
		i++;
	}
	return (NULL);
}
