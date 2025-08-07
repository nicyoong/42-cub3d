/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 00:08:14 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 14:31:05 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_bzero() function writes n zeroes bytes to a string s. 
 *				If n = 0, it does nothing.
 * @param *s	This is a pointer to a memory block that will be set to zero.
 * @param n		This represents the number of bytes to set to zero.
 * @return		The ft_bzero() function performs its operation of setting memory
 *				to zero, it does not return any value.
 */
void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}
