/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft-memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:03:28 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/25 23:21:18 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)s1;
	src = (unsigned char *)s2;
	while (i < n)
	{
		if (dst[i] != src[i])
		{
			return (dst[i] - src[i]);
			break ;
		}
		i++;
	}
	return (0);
}
