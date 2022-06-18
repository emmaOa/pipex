/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:11:50 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/18 19:11:25 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_exit_bonus(void)
{
	write(2, "Error\n", 6);
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
			perror("dup2 main here");
		if (dup2(pp->fd_pipe[pp->i][1], 1) < 0)
			perror("dup2 pipe stdout");
	}
	else if (pp->i == pp->nb_pipe - 1)
	{
		if (dup2(pp->fd_pipe[pp->i - 1][0], 0) < 0)
			perror("dup pipe here");
		if (dup2(pp->fd_file_2, 1) < 0)
			perror("dup pipe stdout");
	}
}

void	ft_fork_here(t_pipe *pp, char *arv[], char *env[])
{
	pp->param = ft_split(arv[pp->i + 3], ' ');
	pp->url = ft_url_bonus(ft_path_bonus(env), pp);
	if (pp->url == NULL)
		ft_exit_bonus();
	if (pp->i == 0 || pp->i == pp->nb_pipe - 1)
		ft_foork_bonus_here(pp);
	else
	{
		if (dup2(pp->fd_pipe[pp->i][1], 1) < 0)
			perror("dup stdout here");
		if (dup2(pp->fd_pipe[pp->i - 1][0], 0) < 0)
			perror("dup stdin");
	}
	close(pp->pipe_here[1]);
	close(pp->pipe_here[0]);
	ft_close(pp);
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus();
	exit(0);
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
			ft_exit_bonus();
		if (pp->fr[pp->i] == 0)
			ft_fork_here(pp, arv, env);
		pp->i++;
	}
}
