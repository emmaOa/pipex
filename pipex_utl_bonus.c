/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:03:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/17 05:30:22 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int	ft_exit_bonus(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

void	ft_cmnd(t_pipe *pp, char arv[], char *env[])
{
	pp->param = ft_param_bonus(arv);
	pp->url = ft_url_bonus(ft_path_bonus(env), pp->param[0]);
	if (pp->url == NULL)
		ft_exit_bonus();
}

void	ft_fork_1_bonus(t_pipe *pp, char *arv[], char *env[])
{
	pp->param = ft_param_bonus(arv[2]);
	pp->url = ft_url_bonus(ft_path_bonus(env), pp->param[0]);
	if (pp->url == NULL)
		ft_exit_bonus();
	dup2(pp->fd_file, 0);
	dup2(pp->fd_pipe[0][1], 1);
	close(pp->fd_pipe[0][1]);
	close(pp->fd_pipe[0][0]);
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus();
}

void	ft_fork_last_bonus(t_pipe *pp, char arv[], char *env[])
{
	pp->param = ft_param_bonus(arv);
	pp->url = ft_url_bonus(ft_path_bonus(env), pp->param[0]);
	if (pp->url == NULL)
		ft_exit_bonus();
	pp->fd_last_file = open(arv, O_CREAT | O_RDWR, 0644);
	if (pp->fd_last_file == -1)
		ft_exit_bonus();
	dup2(pp->fd_last_file, 1);
	dup2(pp->fd_pipe[pp->nb_pipe - 1][0], 0);
	close(pp->fd_pipe[pp->nb_pipe - 1][1]);
	close(pp->fd_pipe[pp->nb_pipe - 1][0]);
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus();
}

t_pipe		*ft_fd_pipe(t_pipe *pp)
{
	int i;

	i = 0;
	while (i < pp->nb_pipe)
	{
		if (pipe(pp->fd_pipe[i]) == -1)
			ft_exit_bonus();
		i++;
	}
	return (pp);
}