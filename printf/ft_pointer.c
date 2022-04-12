/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:52:13 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:46:58 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_h(unsigned long nb, int *rtn)
{
	char	*str;

	if (nb >= 16)
	{
		ft_putnbr_h(nb / 16, rtn);
		ft_putnbr_h(nb % 16, rtn);
	}
	else
	{
		str = "0123456789abcdef";
		ft_putchar(str[nb], rtn);
	}
}

void	ft_pointer(unsigned long p, int *rtn)
{
	ft_putstr("0x", rtn);
	ft_putnbr_h(p, rtn);
}
