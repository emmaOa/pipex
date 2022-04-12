/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 21:58:55 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/25 22:00:20 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *d, const char *s, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*src;

	i = 0;
	dst = (unsigned char *)d;
	src = (unsigned char *)s;
	if (n == 0)
		return (0);
	while ((i < n) && ((dst[i] != '\0') || (src[i] != '\0')))
	{
		if (dst[i] != src[i])
		{
			return (dst[i] - src[i]);
		}
		i++;
	}
	return (0);
}
