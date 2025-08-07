/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:35:02 by tching            #+#    #+#             */
/*   Updated: 2024/06/04 14:41:01 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The isdigit() function tests for a decimal digit character.
 * @param c		The value of the argument to determine in the function. 
 * @return		The isdigit() function returns zero if the character tests false
 *				and returns non-zero if the character tests true.
 */
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
