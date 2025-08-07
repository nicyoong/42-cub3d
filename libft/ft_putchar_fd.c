/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:51:47 by tching            #+#    #+#             */
/*   Updated: 2024/06/12 17:27:09 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_putchar_fd() function writes the character c on fd.
 * @param c		The character to output.
 * @param fd	The file descriptor on which to write.
 * @return		The ft_putchar_fd() function does not return anything.
 */
void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
