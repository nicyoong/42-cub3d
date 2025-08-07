/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:36:50 by tching            #+#    #+#             */
/*   Updated: 2024/06/13 16:09:33 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strrchr() function is identical to strchr(), except it 
 *				locates the last occurrence of c.
 *				The ft_strchr() function locates the first occurrence of c 
 *				(converted to a char) in the string pointed to by s. The 
 *				terminating null character is considered to be part of the 
 *				string; therefore if c is `\0', the functions locate the 
 *				terminating `\0'.
 * @param *s	The string to scanned for.
 * @param c		The character to be searched for.
 * @return		The ft_strrchr() return a pointer to the located character, or
 *				NULL if the character does not appear in the string.
 */
char	*ft_strrchr(char const *s, int c)
{
	unsigned int	i;
	char			*result;
	char			cc;

	i = 0;
	result = NULL;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			result = (char *) &s[i];
		i++;
	}
	if (s[i] == c)
		result = (char *) &s[i];
	return (result);
}
