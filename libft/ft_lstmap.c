/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:17:47 by tching            #+#    #+#             */
/*   Updated: 2024/06/19 20:19:53 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_lstmap() iterates the list ’lst’ and applies the ft ’f'
 * 				on the content of each node. Creates a new list resulting of
 * 				the successive applications of the function ’f’. The ’del’
 * 				function is used to delete the content of a node if needed.
 * @param *lst	The address of a pointer to a node.
 * @param *f	The address of the function used to iterate on the list.
 * @param *del	The address of the function used to delete the content of a 
 * 				node if needed.
 * @return		The new list. NULL if the allocation fails.
 * */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = ft_lstnew(f(lst->content));
	if (!new_lst)
		return (NULL);
	node = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_lst->next = ft_lstnew(f(lst->content));
		if (!new_lst->next)
		{
			ft_lstclear(&node, del);
			return (NULL);
		}
		lst = lst->next;
		new_lst = new_lst->next;
	}
	new_lst->next = NULL;
	return (node);
}
/*void	*my_ft(void *str)
{
	char *s = (char *)str;

	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
		{
			*s -= 32;
		}
		s++;
	}
	return (str);
}
void	del(void *content)
{
	free(content);
}
int main(void)
{
	t_list node1, node2, node3;
	t_list *head;
	t_list *newlist;

	node1.content = strdup("Hello");
	node1.next = &node2;
	
	node2.content = strdup("My");
	node2.next = &node3;

	node3.content = strdup("pyj");
	node3.next = NULL;

	newlist = ft_lstmap(&node1, my_ft, del);

    while (newlist != NULL)
    {
        printf("%s -> ", (char *)newlist->content);
        newlist = newlist->next;
    }
    printf("NULL\n");
	return 0;
}*/
