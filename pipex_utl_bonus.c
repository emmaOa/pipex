/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:03:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/16 16:09:47 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int	ft_exit_bonus(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

// void	ft_close(t_pipe *pp, )

// void	ft_cmnd(t_pipe *pp, char arv[], char *env[])
// {
// 	pp->param = ft_param_bonus(arv, pp);
// 	pp->url = ft_url_bonus(ft_path_bonus(env), pp->param[0]);
// 	if (pp->url == NULL)
// 		ft_exit_bonus();
// }

void	ft_fork_bonus(t_pipe *pp, char *arv[], char *env[], int *fd_pipe[], int arc)
{
	pp->param = ft_split(arv[arc - 4 + pp->i], ' ');
	pp->url = ft_url_bonus(ft_path_bonus(env), pp);
	if (pp->url == NULL)
		ft_exit_bonus();
	dup2(fd_pipe[pp->i + 1][1], 1);
	dup2(fd_pipe[pp->i][0], 0);
	close(fd_pipe[pp->i][0]);
	close(fd_pipe[pp->i + 1][1]);
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus();
}
