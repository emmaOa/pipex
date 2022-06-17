/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:03:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/17 15:31:18 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

void	ft_close(t_pipe *pp)
{
	int	i;

	i = 0;
	while (i < pp->nb_pipe)
	{
		close(pp->fd_pipe[i][0]);
		close(pp->fd_pipe[i][1]);
		i++;
	}
}

char	*ft_url_bonus(char *path, t_pipe *pp)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(path, ':');
	while (tmp[i])
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		tmp[i] = ft_strjoin(tmp[i], pp->param[0]);
		if (access(tmp[i], F_OK) == 0)
			return (tmp[i]);
		i++;
	}
	return (NULL);
}

char	*ft_path_bonus(char *env[])
{
	int		i;
	char	*pt;
	char	*tmp;

	i = 0;
	tmp = NULL;
	pt = "PATH";
	while (env[i])
	{
		if (ft_strncmp(env[i], pt, ft_strlen(pt)) == 0)
			tmp = env[i];
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		tmp[i] = tmp[i + 5];
		i++;
	}
	return (tmp);
}

void	ft_foork_bonus_utl(t_pipe *pp)
{
	if (pp->i == 0)
	{
		if (dup2(pp->fd_file, 0) < 0)
			perror("dup2 main");
		if (dup2(pp->fd_pipe[pp->i][1], 1) < 0)
			perror("dup2 pipe stdout");
	}
	else if (pp->i == pp->nb_pipe - 1)
	{
		if (dup2(pp->fd_pipe[pp->i - 1][0], 0) < 0)
			perror("dup pipe");
		if (dup2(pp->fd_file_2, 1) < 0)
			perror("dup pipe stdout");
	}
}

void	ft_fork_bonus(t_pipe *pp, char *arv[], char *env[])
{
	pp->param = ft_split(arv[pp->i + 2], ' ');
	pp->url = ft_url_bonus(ft_path_bonus(env), pp);
	if (pp->url == NULL)
		ft_exit_bonus();
	if (pp->i == 0 || pp->i == pp->nb_pipe - 1)
		ft_foork_bonus_utl(pp);
	else
	{
		if (dup2(pp->fd_pipe[pp->i][1], 1) < 0)
			perror("dup stdout");
		if (dup2(pp->fd_pipe[pp->i - 1][0], 0) < 0)
			perror("dup stdin");
	}
	ft_close(pp);
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus();
	exit(0);
}
