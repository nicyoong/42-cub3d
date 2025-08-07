/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:31:07 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 20:43:12 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_lstnew() allocates (with malloc) and returns a new node.
 * 				The member variable ’content’ is initialized with the value of
 * 				parameter ’content’. The variable ’next’ is initialized to NULL.
 * @param *content	The content to create the node with.
 * @return		The ft_lstnew() returns the new node.
 * */
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
