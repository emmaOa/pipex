/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/16 23:10:26 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int main(int arc, char *arv[], char *env[])
{
	t_pipe	pp;
	int		x;
 
	x = 0;
	pp.i = 0;
	pp.nb_fork = arc - 3;
	pp.nb_pipe = pp.nb_fork;
	pp.name_file = arv[1];
	pp.fd_pipe = (int **)malloc((pp.nb_pipe + 1) * sizeof(int *));
	while (x < pp.nb_pipe + 1)
	{
       pp.fd_pipe[x] = (int *)malloc(2 * sizeof(int));
		x++;
	}
	pp.fr = (int *)malloc(pp.nb_fork * sizeof(int));
	pp.fd_file = open(pp.name_file, O_RDONLY, 0644);
	if (pp.fd_file == -1)
		exit(1);
	pp.name_file_2 = arv[arc - 1];
	pp.fd_file_2 = open(pp.name_file_2, O_CREAT | O_RDWR, 0644);
	if (pp.fd_file_2 == -1)
		exit(1);
	while (pp.i < pp.nb_pipe + 1)
	{
		if (pipe(pp.fd_pipe[pp.i]) == -1)
			return 1; 
		pp.i++;
	}
	pp.i = 0;

	while (pp.i < pp.nb_fork)
	{
		pp.fr[pp.i] = fork();
		if (pp.fr[pp.i] == -1)
			return 2;
		if (pp.fr[pp.i] == 0)
			ft_fork_bonus(&pp, arv, env);
		pp.i++;
	}
	ft_close(&pp);
	pp.i = 0;
	while (pp.i < pp.nb_fork)
	{
		wait(NULL);
		pp.i++;
	}
	return (0);
}