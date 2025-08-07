/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 19:09:58 by tching            #+#    #+#             */
/*   Updated: 2024/06/12 17:05:50 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strncmp() lexicographically compare the null-terminated
 *				strings s1 and s2. It compares not more than n characters. 
 *				Because ft_strncmp() is designed for comparing strings rather
 *				than binary data, characters that appear after a `\0' character
 *				are not compared.
 * @param *s1	The first string to be compared.
 * @param *s2	The second string to be compared.
 * @param n		The maximum number of characters to compare.
 * @return		The ft_strncmp() function returns an integer greater than, equal
 *				to, or less than 0, according as the string s1 is greater than,
 *				equal to, or less than the string s2.  The comparison is done
 *				using unsigned characters, so that `\200' is greater than `\0'.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (s1[i] != s2[i])
			return ((unsigned chars1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
