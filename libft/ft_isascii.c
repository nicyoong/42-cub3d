/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:26:26 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 14:33:35 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The isascii() function tests for an ASCII character, which is 
 *				any character between 0 and octal 0177 inclusive.
 * @param c		The value of the argument to determine in the function. 
 * @return		The isascii() function returns zero if the character tests false
 *				and returns non-zero if the character tests true.
 */
int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
