/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:55:04 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 20:59:32 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 *  @brief		The ft_lstsize() counts the number of nodes in a list.
 *  @param *lst	The beginning of the list.
 *  @return		The length of the list.
 *  */
int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*int main(void)
{
    t_list node1;
    t_list node2;
    t_list node3;

    node1.content = "Node 1";
    node1.next = &node2;

    node2.content = "Node 2";
    node2.next = &node3;

    node3.content = "Node 3";
    node3.next = NULL;

	printf("Number of nodes : %d", ft_lstsize(&node1));
	return (0);
}*/
