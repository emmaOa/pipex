/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 01:26:34 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/18 17:49:15 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

void	ft_fork_1(t_pipe *pp, char *arv[], char *env[])
{
	pp->param = ft_param(arv[2]);
	pp->url = ft_url(ft_path(env), pp->param[0]);
	if (pp->url == NULL)
		ft_exit();
	dup2(pp->fd_file, 0);
	dup2(pp->fd[1], 1);
	close(pp->fd[1]);
	close(pp->fd[0]);
	if (execve(pp->url, pp->param, env) < 0)
		exit(0);
}

void	ft_fork_2(t_pipe *pp, char *arv[], char *env[])
{
	pp->param = ft_param(arv[3]);
	pp->url = ft_url(ft_path(env), pp->param[0]);
	if (pp->url == NULL)
		ft_exit();
	pp->fd2_file = open(arv[4], O_CREAT | O_RDWR, 0644);
	if (pp->fd2_file == -1)
		exit(0);
	dup2(pp->fd2_file, 1);
	dup2(pp->fd[0], 0);
	close(pp->fd[1]);
	close(pp->fd[0]);
	if (execve(pp->url, pp->param, env) < 0)
		exit(0);
}
