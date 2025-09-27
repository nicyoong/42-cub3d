/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:25:07 by tching            #+#    #+#             */
/*   Updated: 2025/09/27 12:44:38 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_atoi() function converts the initial portion of the 
 *				string pointed to by str to int representation.
 * @param *str	Access the characters in the string and convert them into int.
 * @return		The ft_atoi() returns final int derived from the string.
 */
int	ft_atoi(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f'
		|| *str == '\t' || *str == '\r' || *str == '\v')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return ((int)result * sign);
}
