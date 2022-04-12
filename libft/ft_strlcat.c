/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:47:41 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/25 21:34:26 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d;
	size_t	i;
	size_t	k;

	k = ft_strlen(dst) + ft_strlen(src);
	d = ft_strlen(dst);
	i = 0;
	if (!src || !dst)
		return (ft_strlen(src));
	if (dstsize <= d)
		return (dstsize + ft_strlen(src));
	while (src[i] && i < (dstsize - d - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (k);
}
