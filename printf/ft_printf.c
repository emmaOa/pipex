/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:38:07 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:46:59 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(const char *str, va_list ap, int *rtn)
{
	if (*str == 'c')
		ft_putchar(va_arg(ap, int), rtn);
	else if (*str == 's')
		ft_putstr(va_arg(ap, void *), rtn);
	else if (*str == 'p')
		ft_pointer(va_arg(ap, unsigned long), rtn);
	else if ((*str == 'd') || (*str == 'i'))
		ft_putnbr(va_arg(ap, int), rtn);
	else if (*str == 'u')
		ft_putnbr_uns(va_arg(ap, int), rtn);
	else if (*str == 'x')
		ft_putnbr_hl(va_arg(ap, int), rtn);
	else if (*str == 'X')
		ft_putnbr_hu(va_arg(ap, int), rtn);
	else if (*str == '%')
		ft_putchar('%', rtn);
	else
		ft_putchar(*str, rtn);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		rtn;
	va_list	ap;

	va_start(ap, str);
	i = 0;
	rtn = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_check(&str[++i], ap, &rtn);
		else if (str[i])
			ft_putchar(str[i], &rtn);
		if (str[i])
			i++;
	}
	va_end(ap);
	return (rtn);
}
