/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:00:45 by tching            #+#    #+#             */
/*   Updated: 2024/06/18 21:06:43 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_lstlast() function returns the last node of the list.
 * @param *lst	The beginning of the lst.
 * @return		Last node of the list.
 */
t_list	*ft_lstlast(t_list	*lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew("Hello"));
    ft_lstadd_back(&list, ft_lstnew("World"));
    ft_lstadd_back(&list, ft_lstnew("from"));
    ft_lstadd_back(&list, ft_lstnew("C"));

    t_list  *last = ft_lstlast(list);

    if (last)
        printf("Last element: %s\n", (char *)last->content);
    else
        printf("The list is empty.\n");

    ft_lstclear(&list, free);

    return 0;
}*/
