/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:45:31 by tching            #+#    #+#             */
/*   Updated: 2024/06/20 14:29:22 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 *  @brief		The ft_lstadd_front() adds the node ’new’ at the beginning 
 *  			of the list.
 *  @param **lst	The address of a pointer to the first link of a list.
 *  @param *new		The address of a pointer to the node to be added to the list.
 *  @return		The ft_lstadd_front() returns no value.
 *  */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int main(void)
{
    t_list  *head;
    t_list node1;
    t_list node2;

    node1.content = "1st Node 2nd";
    node1.next = NULL;

    node2.content = "2nd Node 1st";
    node2.next = &node1;

    *head = node1;	
    ft_lstadd_front(&head, &node2); 

    t_list *current = head;
    while (current != NULL)
    {
        printf("%s -> ", (char *)current->content);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}*/
