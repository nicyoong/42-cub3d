/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:36:02 by tching            #+#    #+#             */
/*   Updated: 2024/06/12 17:08:41 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The memcmp() function compares byte string s1 against byte 
 *				string s2. Both strings are assumed to be n bytes long.
 * @param *s1	A pointer to the first memory block to be compared.
 * @param *s2	A pointer to the second memory block to be compared.
 * @param n		The no. of bytes to be compared in *s1 and *s2.
 * @return		The memcmp() function returns 0 if the two strings are identical
 *				otherwise returns the difference between the first 2 differing
 *				bytes(treated as unsigned char values, so that `\200' is
 *				greater than `\0' for example).  Zero-length strings are always
 *				identical. This behavior is not required by C and portable code
 *				should only depend on the sign of the returned value.
 */
int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;
	size_t				i;

	cs1 = (const unsigned char *)s1;
	cs2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (cs1[i] != cs2[i])
			return (cs1[i] - cs2[i]);
		i++;
	}
	return (0);
}
