/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:22:40 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/25 20:28:12 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"                                          

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		nb *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nb >= 10)
		ft_putnbr_fd((nb / 10), fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
