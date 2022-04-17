/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:05:56 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/07 05:06:05 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)s;
	while (p[i] && (char)c != p[i])
		i++;
	if ((char)c == p[i])
		return (p + i);
	return (NULL);
}

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
