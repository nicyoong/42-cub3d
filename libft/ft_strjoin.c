/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 16:55:10 by tching            #+#    #+#             */
/*   Updated: 2024/06/15 14:06:39 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_strjoin() function works basically the same way as 
 *				ft_strlcat does, but instead of passing it a destination string
 *				that has to be correctly allocated as a parameter, we only pass
 *				two strings and ft_strjoin will allocate the required memory for
 *				both of them plus the NUL-terminating character.
 * @param *s1	The prefix string.
 * @param *s2	The suffix string. To append to s1.
 * @return		The ft_strjoin() returns the new string s3; NULL if the memory 
 *				allocation failed.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (s3);
}
