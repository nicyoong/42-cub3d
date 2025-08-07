/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:46:05 by tching            #+#    #+#             */
/*   Updated: 2024/06/15 18:00:55 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_split() allocate (with malloc) and returns an array of
 *				strings obtained by splitting s with the character c, used as
 *				delimiter. The returned array must be NUL-terminated.
 * @param *s	The string to split.
 * @param c		The delimiter character.
 * @return		The ft_split() function returns an array of strings resulting 
 *				from the splitting of s; NULL if the memory allocation failed.
 */
static	size_t	ft_countwords(char const *s, char c);
char			*find_next_word(char const *s, char c, size_t *word_len);

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	lst = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!lst)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			lst[i] = find_next_word(s, c, &word_len);
			if (!lst[i])
				return (NULL);
			s += word_len;
			i++;
		}
	}
	lst[i] = NULL;
	return (lst);
}

static	size_t	ft_countwords(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	*find_next_word(char const *s, char c, size_t *word_len)
{
	if (!ft_strchr(s, c))
		*word_len = ft_strlen(s);
	else
		*word_len = ft_strchr(s, c) - s;
	return (ft_substr(s, 0, *word_len));
}
