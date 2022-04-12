/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 04:37:36 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/26 01:22:57 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_len(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str_nb;
	long	i;

	i = count_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str_nb = malloc(sizeof(char) * i + 1);
	if (!str_nb)
		return (NULL);
	if (n < 0)
	{
		str_nb[0] = '-';
		n *= -1;
	}
	if (n == 0)
		str_nb[0] = '0';
	str_nb[i--] = '\0';
	while (n != 0)
	{
		str_nb[i] = (n % 10) + '0';
		i--;
		n = n / 10;
	}
	return (str_nb);
}
