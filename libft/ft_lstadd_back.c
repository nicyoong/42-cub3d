/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:08:44 by tching            #+#    #+#             */
/*   Updated: 2024/06/20 14:27:23 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief	The ft_lstadd_back() adds the node ’new’ at the end of the list.
 * @param **lst	The address of a pointer to the first link of a list.
 * @param *new	The address of a pointer to the node to be added to the list.
 * @return	None.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
/*int main(void)
{
    t_list *head;
	t_list node1;
    t_list node2;
	*head = NULL;
    node1.content = "Who";
    node1.next = NULL;

    node2.content = "What";
    node2.next = NULL;

    t_list *head = &node1;
    ft_lstadd_back(&head, &node2); 

    t_list *current = head;     
    while (current != NULL)
    {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
 * */
