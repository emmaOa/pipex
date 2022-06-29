/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 05:15:05 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/29 05:17:50 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free_bonus(char **tabl, int start, int len)
{
	while (start < len)
	{
		free(tabl[start]);
		start++;
	}
	free(tabl);
}

void	ft_free(char **tabl, int start, int len)
{
	while (start < len)
	{
		free(tabl[start]);
		start++;
	}
	free(tabl);
}

void	ft_free_bonus_int(int **tabl, int start, int len)
{
	while (start < len)
	{
		free(tabl[start]);
		start++;
	}
	free(tabl);
}

int	ft_len(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
	{
		i++;
	}
	return (i);
}

int	ft_len_bonus(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		i++;
	return (i);
}
