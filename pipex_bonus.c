/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/24 21:20:48 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
			ft_exit_bonus("error: pipe failed", pp);
		pp->i++;
	}
}

void	ft_open_files(t_pipe *pp, char *arv[], int arc)
{
	pp->name_file = arv[1];
	pp->fd_file = open(pp->name_file, O_RDONLY, 0644);
	if (pp->fd_file == -1)
		ft_exit_bonus("open file is failed ", pp);
	pp->name_file_2 = arv[arc - 1];
	pp->fd_file_2 = open(pp->name_file_2, O_CREAT | O_RDWR, 0644);
	if (pp->fd_file_2 == -1)
		ft_exit_bonus("open file is failed ", pp);
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
			ft_exit_bonus("error: failed in fork", pp);
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
		ft_exit_bonus("failed pipe here_doc", pp);
	ft_putstr_fd("pipe heredoc> ", 1);
	pp->tmp = get_next_line(0);
	ft_putstr_fd(pp->tmp, pp->pipe_here[1]);
	while (ft_strncmp(pp->tmp, arv[2], ft_strlen(arv[2])) != 0)
	{
		free(pp->tmp);
		ft_putstr_fd("pipe heredoc> ", 1);
		pp->tmp = get_next_line(0);
		ft_putstr_fd(pp->tmp, pp->pipe_here[1]);
	}
	free(pp->tmp);
}
