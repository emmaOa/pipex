/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:30:47 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:46:43 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *rtn)
{
	int	val;

	val = nb;
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", rtn);
		return ;
	}
	if (nb < 0)
	{
		val = nb * -1;
		ft_putchar('-', rtn);
	}
	if (val >= 10)
	{
		ft_putnbr(val / 10, rtn);
		ft_putnbr(val % 10, rtn);
	}
	else
	{
		val = val + '0';
		ft_putchar(val, rtn);
	}
}
