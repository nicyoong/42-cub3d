/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:47:58 by tching            #+#    #+#             */
/*   Updated: 2024/06/06 16:36:59 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The memset() function writes len bytes of value c (converted 
 *				to an unsigned char) to the string b.
 * @param *b	A pointer to the memory block to fill.
 * @param c		The value to be set. The value is passed as an int, but the 
 *				function fills the block of memory using the unsigned char
 *				conversion of this value.
 * @param len	The no. of bytes to be set to the value.
 * @return		The memset() function returns to its first argument.
 */
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = (unsigned char *)b;
	while (len--)
		*(s++) = (unsigned char)c;
	return (b);
}
