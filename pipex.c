/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:03:58 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/29 05:36:42 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_url_two(char *comnd, char *path)
{
	char	*cmd_path;
	char	**url;
	char	*tmp;
	int		i;

	i = 0;
	url = ft_split(path, ':');
	while (url[i])
	{
		cmd_path = ft_strjoin(url[i], "/");
		tmp = cmd_path;
		cmd_path = ft_strjoin(cmd_path, comnd);
		free(tmp);
		if (access(cmd_path, F_OK) == 0)
		{
			ft_free(url, i, ft_len(url));
			return (cmd_path);
		}
		free(cmd_path);
		free(url[i]);
		i++;
	}
	free(url);
	return (NULL);
}

char	*ft_url(char *path, char *comnd)
{
	char	*ret;

	if (ft_strchr(comnd, '/'))
	{
		if (access(comnd, F_OK) == 0)
			return (comnd);
		return (NULL);
	}
	ret = ft_url_two(comnd, path);
	return (ret);
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
	if (!tmp)
		ft_exit("path not founde: ");
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
		ft_exit("number argement not valid");
	pp.name_file = arv[1];
	pp.fd_file = open(pp.name_file, O_RDONLY, 0644);
	if (pp.fd_file == -1)
		ft_exit("problem in first open");
	if (pipe(pp.fd) == -1)
		ft_exit("problem in pipe\n");
	pp.fr1 = fork();
	if (pp.fr1 == -1)
		ft_exit("problem in first fork");
	if (pp.fr1 == 0)
		ft_fork_1(&pp, arv, env);
	if (pp.fr1 != 0)
		pp.fr2 = fork();
	if (pp.fr2 == -1)
		ft_exit("problem in second fork");
	if (pp.fr2 == 0)
		ft_fork_2(&pp, arv, env);
	close(pp.fd[1]);
	close(pp.fd[0]);
	while
		(wait(NULL) != -1);
}
