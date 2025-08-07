/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 15:01:40 by tching            #+#    #+#             */
/*   Updated: 2024/06/12 20:29:53 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strdup() function allocates sufficient memory for a copy
 *				of the string s1, does the copy, and returns a pointer to it.
 *				The pointer may subsequently be used as an argument to the 
 *				function free. If insufficient memory is available, NULL is
 *				returned and errno is set to ENOMEM.
 * @param *s1	The string to duplicate to *dst.
 * @return		The ft_strdup() returns the allocated and copied string *dst.
 */
char	*ft_strdup(char const *s1)
{
	char	*dst;

	dst = (char *) malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (NULL);
	ft_memcpy(dst, s1, ft_strlen(s1) + 1);
	return (dst);
}
