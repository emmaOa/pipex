/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:48:37 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:46:49 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hl(unsigned int nb, int *rtn)
{
	char	*str;

	if (nb >= 16)
	{
		ft_putnbr_hl(nb / 16, rtn);
		ft_putnbr_hl(nb % 16, rtn);
	}
	else
	{
		str = "0123456789abcdef";
		ft_putchar(str[nb], rtn);
	}
}
