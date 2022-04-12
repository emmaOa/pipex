/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftstrnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:39:51 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/25 22:01:38 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;
	char	*f;

	i = 0;
	s = (char *)str;
	f = (char *)to_find;
	if (f[0] == '\0')
		return (s);
	while (s[i] != '\0' && i < len)
	{
		j = 0;
		while (f[j] == s[i + j] && (i + j) < len)
		{
			if (f[j + 1] == '\0')
			{
				return (s + i);
			}
			j++;
		}
		i++;
	}
	return (0);
}
