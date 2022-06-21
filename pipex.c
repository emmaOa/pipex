/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:03:58 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/21 04:48:47 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_url(char *path, char *comnd)
{
	int		i;
	char	**url;
	char	*cmd_path;

	i = 0;
	if (ft_strchr(comnd, '/'))
	{
		if (access(comnd, F_OK) == 0)
			return (comnd);
		return (NULL);
	}
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

char	**ft_param(char *arv)
{
	int		i;
	char	**param;

	i = 0;
	param = ft_split(arv, ' ');
	return (param);
}

int	main(int arc, char *arv[], char *env[])
{
	t_pipe	pp;

	if (arc != 5)
		ft_exit("number argement not valid", &pp);
	pp.name_file = arv[1];
	pp.fd_file = open(pp.name_file, O_RDONLY, 0644);
	if (pp.fd_file == -1)
		ft_exit("problem in first open", &pp);
	if (pipe(pp.fd) == -1)
		ft_exit("problem in pipe\n", &pp);
	pp.fr1 = fork();
	if (pp.fr1 == -1)
		ft_exit("problem in first fork", &pp);
	if (pp.fr1 == 0)
		ft_fork_1(&pp, arv, env);
	if (pp.fr1 != 0)
		pp.fr2 = fork();
	if (pp.fr2 == -1)
		ft_exit("problem in second fork", &pp);
	if (pp.fr2 == 0)
		ft_fork_2(&pp, arv, env);
	close(pp.fd[1]);
	close(pp.fd[0]);
	while (wait(NULL) != -1);
}
