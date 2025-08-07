/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:43:49 by tching            #+#    #+#             */
/*   Updated: 2024/06/19 20:17:54 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_lstclear() deletes and frees the given node and every
 * 				successor of that node, using the function ’del’ and free.
 * 				Finally, the pointer to the list must be set to NULL.
 * @param **lst	The address of a pointer to a node.
 * @param *del	The address of the ft used to delete the content of the node.
 * @return		None.
 * */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = temp;
	}
}
/*void custom_function(void *content)
{
    free(content);
}
int main(void)
{
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew("Hello"));
    ft_lstadd_back(&list, ft_lstnew("World"));
    ft_lstadd_back(&list, ft_lstnew("from"));
    ft_lstadd_back(&list, ft_lstnew("C"));

    ft_lstclear(&list, custom_free);

    return 0;
}*/