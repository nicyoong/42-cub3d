/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:46:21 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 16:57:53 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The isalnum() function tests for any character for which 
 *				isalpha(3) or isdigit(3) is true. The value of the argument must
 *				be representable as an unsigned char or the value of EOF.
 * @param c		The value of the argument to determine in the function. 
 * @return		The isalnum() function returns zero if the character tests false
 *				and returns non-zero if the character tests true.
 */
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
