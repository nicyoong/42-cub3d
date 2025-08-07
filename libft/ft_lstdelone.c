/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:16:16 by tching            #+#    #+#             */
/*   Updated: 2024/06/19 20:21:32 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_lstdelone() takes as a parameter a node and frees the
 * 				memory of the node’s content using the function ’del’ given as
 * 				a parameter and free the node. 
 * 				The memory of ’next’ must not be freed.
 * @param *lst	The node to free.
 * @param *del	The address of the function used to delete the content.
 * @return		None.
 * */
void	ft_lstdelone(t_list	*lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
