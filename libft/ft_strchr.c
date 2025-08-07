/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:19:53 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 15:42:51 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strchr() function locates the first occurrence of c 
 *				(converted to a char) in the string pointed to by s. The 
 *				terminating null character is considered to be part of the 
 *				string; therefore if c is `\0', the functions locate the 
 *				terminating `\0'.
 * @param *s	The string to scanned for.
 * @param c		The character to be searched for.
 * @return		The ft_strchr() return a pointer to the located character, or
 *				NULL if the character does not appear in the string.
 */
char	*ft_strchr(char const *s, int c)
{
	char	cc;

	cc = (char) c;
	while (*s)
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (*s == cc)
		return ((char *)s);
	return (NULL);
}
