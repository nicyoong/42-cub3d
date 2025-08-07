/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tching <tching@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:35:28 by tching            #+#    #+#             */
/*   Updated: 2024/06/13 17:25:52 by tching           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * @brief		The ft_putnbr_fd() function writes the int n on fd.
 * @param n		The int to write.
 * @param fd	The file descriptor on which to write.
 * @return		The ft_putnbr_fd() function does not return anything.
 */
void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd((nbr / 10), fd);
		ft_putchar_fd((nbr % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((nbr + '0'), fd);
}
