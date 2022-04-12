/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:27:32 by iouazzan          #+#    #+#             */
/*   Updated: 2021/11/05 16:14:33 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <stdlib.h>
// #include <strings.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	k;
	char	*p;

	k = count * size;
	p = malloc(k);
	if (!p)
		return (NULL);
	ft_bzero(p, k);
	return (p);
}
