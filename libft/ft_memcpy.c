/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:20:36 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/26 02:11:49 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*k;
	size_t	i;

	k = (char *)dst;
	i = 0;
	if (!k && !src)
		return (NULL);
	while (i < n)
	{
		k[i] = *(char *)src;
		i++;
		src++;
	}
	return (dst);
}
