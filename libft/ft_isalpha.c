/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:41:29 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 17:43:50 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The isalpha() function tests for any character for which
 *				isupper(3) or islower(3) is true. The value of the argument must
 *				be representable as an unsigned char or the value of EOF.
 * @param c		The value of the argument to determine in the function. 
 * @return		The isalpha() function returns zero if the character tests false
 *				and returns non-zero if the character tests true.
 */
int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
