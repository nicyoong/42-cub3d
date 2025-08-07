/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:48:08 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 15:14:00 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_striteri() function takes two parameters, the first one
 *				is a string, and the second one is a function. What ft_striteri
 *				does is apply the function f to every character of the string s.
 *				It passes the index of the character in the string, and a pointer
 *				to the character to the function f. The function f directly
 *				modifies the value of the character in the original string.
 * @param *s1	The string to duplicate to *dst.
 * @return		The ft_striteri() returns the allocated and copied string *dst.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
