/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:27:51 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/26 01:19:34 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*c;
	size_t	i;

	i = 0;
	p = (char *)s;
	if (!s)
		return (0);
	if (start >= ft_strlen(p))
		c = malloc(1);
	else if (len >= (ft_strlen(p) - start))
		c = malloc(ft_strlen(s) - start + 1);
	else
		c = malloc(len +1);
	if (!c)
		return (NULL);
	while (p[i] && i < len && (start + i) < ft_strlen(p))
	{
		c[i] = p[start + i];
		i++;
	}
	c[i] = '\0';
	return (c);
}
