/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/17 06:01:31 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

char	*ft_url_bonus(char *path, char *comnd)
{
	int		i;
	char	**url;
	char	*cmd_path;

	(void)comnd;
	i = 0;
	url = ft_split(path, ':');
	while (url[i])
	{
		cmd_path = ft_strjoin(url[i], "/");
		cmd_path = ft_strjoin(cmd_path, comnd);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		i++;
	}
	return (NULL);
}

char	*ft_path_bonus(char *env[])
{
	int		i;
	int		j;
	char	*pt;
	char	*tmp;

	i = 0;
	j = 0;
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

char	**ft_param_bonus(char *arv)
{
	int		i;
	char	**param;

	i = 0;
	param = ft_split(arv, ' ');
	return (param);
}

int main(int arc, char *arv[], char *env[])
{
	t_pipe	pp;
	int i;
	int	j;

	i = 3;
	j = 1;
	pp.nb_cmnd = arc - 3;
	pp.nb_pipe = pp.nb_cmnd - 1;
	pp.name_file = arv[1];
	pp.fd_file = open(pp.name_file, O_RDONLY, 0644);
	if (pp.fd_file == -1)
		ft_exit_bonus();
	ft_fd_pipe(&pp);
	pp.fr1 = fork();
	if (pp.fr1 == -1)
		ft_exit_bonus();
	if (pp.fr1 == 0)
		ft_fork_1_bonus(&pp, arv, env);
	while (pp.nb_cmnd - 2 > 0)
	{
		pp.fr1 = fork();
		if (pp.fr1 == -1)
			ft_exit_bonus();
		if (pp.fr1 == 0)
		ft_cmnd(&pp, arv[arc - i], env);
		dup2(pp.fd_pipe[j - 1][0], 0);
		dup2(pp.fd_pipe[j][1], 1);
		close(pp.fd_pipe[j][1]);
		close(pp.fd_pipe[j][0]);
		i++;
		j++;
		if (execve(pp.url, pp.param, env) < 0)
		ft_exit_bonus();
	}
	pp.fr1 = fork();
	if (pp.fr1 == -1)
		ft_exit_bonus();
	if (pp.fr1 == 0)
		ft_fork_last_bonus(&pp, arv[arc - 1], env);
	return (0);
}
