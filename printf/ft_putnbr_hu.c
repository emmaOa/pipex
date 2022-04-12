/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:32:34 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:46:47 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hu(unsigned int nb, int *rtn)
{
	char	*str;

	if (nb >= 16)
	{
		ft_putnbr_hu(nb / 16, rtn);
		ft_putnbr_hu(nb % 16, rtn);
	}
	else
	{
		str = "0123456789ABCDEF";
		ft_putchar(str[nb], rtn);
	}
}
