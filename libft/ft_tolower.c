/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:28:48 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 17:34:19 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_tolower() function converts an upper-case letter to the
 *				corresponding lower-case letter. The argument must be
 *				representable as an unsigned char or the value of EOF.
 * @param c		The value of the argument to determine in the function.
 * @return		If the argument is an upper-case letter, the ft_tolower()function
 *				returns the corresponding lower-case letter if there is one; 
 *				otherwise, the argument is returned unchanged.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
