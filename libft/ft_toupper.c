/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:50:56 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 14:55:33 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_toupper() function converts an lower-case letter to the
 *				corresponding upper-case letter. The argument must be
 *				representable as an unsigned char or the value of EOF.
 * @param c		The value of the argument to determine in the function.
 * @return		If the argument is an lower-case letter, the ft_toupper()function
 *				returns the corresponding upper-case letter if there is one; 
 *				otherwise, the argument is returned unchanged.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
