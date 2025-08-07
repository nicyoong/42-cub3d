/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:32:14 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 15:43:20 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strmapi() function takes two parameters, the first one
 *				is a string, and the second one is a function. What ft_strmapi
 *				does is apply the function f to every character of the string s.
 *				It passes the index of the character in the string, and a pointer
 *				to the character to the function f. The function f directly
 *				modifies the value of the character in the original string.
 * @param *s	The string over which to iterate.
 * @param *f	The function to apply to each character.
 * @return		The ft_strmapi() returns a new string resulting of the successive
 *				applications of 'f'; NULL if the memory allocations failed.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (!s)
		return (NULL);
	result = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < ft_strlen(s))
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
