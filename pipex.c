/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:03:58 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/15 02:11:36 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

char	*ft_url(char *path, char *comnd)
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

char	*ft_path(char *env[])
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

char	**ft_param(char *arv)
{
	char	**param;

	param = ft_split(arv, ' ');
	return (param);
}

int	main(int arc, char *arv[], char *env[])
{
	t_pipe	pp;

	(void)arc;
	pp.name_file = arv[1];
	pp.fd_file = open(pp.name_file, O_RDONLY, 0644);
	if (pp.fd_file == -1)
		ft_exit();
	if (pipe(pp.fd) == -1)
		ft_exit();
	pp.fr1 = fork();
	if (pp.fr1 == -1)
		ft_exit();
	if (pp.fr1 == 0)
		ft_fork_1(&pp, arv, env);
	if (pp.fr1 != 0)
		pp.fr2 = fork();
	if (pp.fr2 == -1)
		ft_exit();
	if (pp.fr2 == 0)
		ft_fork_2(&pp, arv, env);
	close(pp.fd[1]);
	close(pp.fd[0]);
	wait(NULL);
}
