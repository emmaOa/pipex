/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:50:41 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:46:45 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uns(unsigned int nb, int *rtn)
{
	unsigned int	val;
	unsigned int	print;

	val = nb;
	if (val >= 10)
	{
		print = val / 10;
		ft_putnbr(print, rtn);
		print = val % 10;
		ft_putnbr(print, rtn);
	}
	else
	{
		val = val + '0';
		ft_putchar(val, rtn);
	}
}
