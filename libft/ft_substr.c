/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:48:16 by tching            #+#    #+#             */
/*   Updated: 2024/06/15 14:00:41 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_substr() allocate (with malloc) and return a new string
 *				from the string s. This new string starts at index 'start' and
 *				has a maximum size of 'len'.
 * @param *s	The string from which to create the substring.
 * @param start	The start index of the substring in the string s.
 * @param len	The maximum length of the substring.
 * @return		The ft_substr() function returns the new string; NULL if the
 *				memory allocation failed.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	if (len < ft_strlen(s))
		str = malloc((len + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == 0)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
