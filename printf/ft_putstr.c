/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:33:48 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/02 16:47:07 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str, int *rtn)
{
	int	len;

	if (!str)
	{
		ft_putstr("(null)", rtn);
		return ;
	}
	len = ft_strlen(str);
	write (1, str, len);
	*rtn += len;
}
