/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/18 16:38:53 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

void	ft_pipe(t_pipe *pp)
{
	int	x;

	x = 0;
	pp->i = 0;
	pp->fd_pipe = (int **)malloc((pp->nb_pipe + 1) * sizeof(int *));
	while (x < pp->nb_pipe + 1)
	{
		pp->fd_pipe[x] = (int *)malloc(2 * sizeof(int));
		x++;
	}
	while (pp->i < pp->nb_pipe + 1)
	{
		if (pipe(pp->fd_pipe[pp->i]) == -1)
			ft_exit_bonus();
		pp->i++;
	}
}

void	ft_open_files(t_pipe *pp, char *arv[], int arc)
{
	pp->name_file = arv[1];
	pp->fd_file = open(pp->name_file, O_RDONLY, 0644);
	if (pp->fd_file == -1)
		exit(1);
	pp->name_file_2 = arv[arc - 1];
	pp->fd_file_2 = open(pp->name_file_2, O_CREAT | O_RDWR, 0644);
	if (pp->fd_file_2 == -1)
		exit(1);
}

void	ft_main_fork(t_pipe *pp, int arc, char *arv[], char *env[])
{
	pp->nb_fork = arc - 3;
	pp->fr = (int *)malloc(pp->nb_fork * sizeof(int));
	pp->i = 0;
	while (pp->i < pp->nb_fork)
	{
		pp->fr[pp->i] = fork();
		if (pp->fr[pp->i] == -1)
			ft_exit_bonus();
		if (pp->fr[pp->i] == 0)
			ft_fork_bonus(pp, arv, env);
		pp->i++;
	}
}

void	ft_wait(t_pipe *pp)
{
	pp->i = 0;
	while (pp->i < pp->nb_fork)
	{
		wait(NULL);
		pp->i++;
	}
}

void	ft_here_doc(t_pipe *pp, char *arv[])
{
	pp->pipe_here = (int *)malloc(2 * sizeof(int));
	if (pipe(pp->pipe_here) == -1)
		ft_exit_bonus();
	pp->fd_tmp_file = open("tmp_file->txt", O_CREAT | O_RDWR, 0644);
	ft_putstr_fd("pipe heredoc> ", 1);
	pp->tmp = get_next_line(0);
	pp->tmp = ft_strjoin(pp->tmp, "\0");
	ft_putstr_fd(pp->tmp, pp->fd_tmp_file);
	while (ft_strncmp(pp->tmp, arv[2], ft_strlen(arv[2])) != 0)
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		pp->tmp = get_next_line(0);
		pp->tmp = ft_strjoin(pp->tmp, "\0");
		ft_putstr_fd(pp->tmp, pp->fd_tmp_file);
		if (!pp->tmp)
			ft_exit_bonus();
	}
	dup2(pp->pipe_here[1], pp->fd_tmp_file);
	close(pp->fd_tmp_file);
}
