/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:07:09 by tching            #+#    #+#             */
/*   Updated: 2024/06/19 16:15:55 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_lstiter() iterates the list ’lst’ and applies the
 * 				function ’f’ on the content of each node.
 * @param *lst	The address of a pointer to a node.
 * @param *f	The address of the function used to iterate on the list.
 * @return		None.
 * */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*void custom_function(void *content)
{
    ft_putstr_fd(content, 1);
    ft_putchar_fd('\n', 1);
}
int main(void)
{
    t_list *list = NULL;
    ft_lstadd_back(&list, ft_lstnew("Hello"));
    ft_lstadd_back(&list, ft_lstnew("World"));
    ft_lstadd_back(&list, ft_lstnew("from"));
    ft_lstadd_back(&list, ft_lstnew("C"));

    ft_lstiter(list, custom_function);
	return 0;
}*/