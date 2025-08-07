/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:42:07 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 14:43:11 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The isprint() function tests for any printing character, 
 *				including space (` '). The value of the argument must be
 *				representable as an unsigned char or the value of EOF.
 * @param c		The value of the argument to determine in the function. 
 * @return		The isprint() function returns zero if the character tests false
 *				and returns non-zero if the character tests true.
 */
int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
