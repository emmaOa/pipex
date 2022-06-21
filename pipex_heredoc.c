/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:11:50 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/21 04:42:20 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit_bonus(char *s, t_pipe *pp)
{
	if (ft_strncmp(s, "command not founde: ", ft_strlen(s)) == 0)
	{
		s = ft_strjoin(s, pp->param[0]);
	}
	perror(s);
	exit (1);
}

void	ft_open_files_here(t_pipe *pp, char *arv[], int arc)
{
	pp->name_file_2 = arv[arc - 1];
	pp->fd_file_2 = open(pp->name_file_2, O_CREAT | O_RDWR, 0644);
	if (pp->fd_file_2 == -1)
		exit(1);
}

void	ft_foork_bonus_here(t_pipe *pp)
{
	if (pp->i == 0)
	{
		if (dup2(pp->pipe_here[0], 0) < 0)
			ft_exit_bonus("failed dup2 stdin first command", pp);
		if (dup2(pp->fd_pipe[pp->i][1], 1) < 0)
			ft_exit_bonus("failed dup2 stdout first command", pp);
	}
	else
	{
		if (dup2(pp->fd_pipe[pp->i - 1][0], 0) < 0)
			ft_exit_bonus("failed dup2 stdin last command", pp);
		if (dup2(pp->fd_file_2, 1) < 0)
			ft_exit_bonus("failed dup2 stdout last command", pp);
	}
}

void	ft_fork_here(t_pipe *pp, char *arv[], char *env[])
{
	pp->param = ft_split(arv[pp->i + 3], ' ');
	pp->url = ft_url_bonus(ft_path_bonus(env), pp);
	if (pp->url == NULL)
		ft_exit_bonus("command not founde", pp);
	if (pp->i == 0 || pp->i == pp->nb_pipe - 1)
		ft_foork_bonus_here(pp);
	else
	{
		if (dup2(pp->fd_pipe[pp->i][1], 1) < 0)
			ft_exit_bonus("failed dup2 stdout last command", pp);
		if (dup2(pp->fd_pipe[pp->i - 1][0], 0) < 0)
			ft_exit_bonus("failed dup2 stdin last command", pp);
	}
	close(pp->pipe_here[1]);
	close(pp->pipe_here[0]);
	ft_close(pp);
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus("command not execute", pp);
}

void	ft_main_fork_here(t_pipe *pp, int arc, char *arv[], char *env[])
{
	pp->nb_fork = arc - 4;
	pp->fr = (int *)malloc(pp->nb_fork * sizeof(int));
	pp->i = 0;
	while (pp->i < pp->nb_fork)
	{
		pp->fr[pp->i] = fork();
		if (pp->fr[pp->i] == -1)
			ft_exit_bonus("fork here_doc is failed", pp);
		if (pp->fr[pp->i] == 0)
			ft_fork_here(pp, arv, env);
		pp->i++;
	}
}
