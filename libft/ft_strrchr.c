/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 13:46:59 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/26 01:17:41 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*dst;

	dst = (char *)s;
	i = ft_strlen(dst);
	while (i >= 0)
	{
		if (dst[i] == (char)c)
			return (dst + i);
		i--;
	}
	return (NULL);
}
