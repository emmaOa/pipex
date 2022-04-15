#include "pipex.h"
#include <stdio.h>

int	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

char	*ft_url(char *path, char *comnd)
{
	int i;
	char **url;
	char *cmd_path;

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

char *ft_path(char *env[])
{
	int i;
	int j;
	char *pt;
	char *tmp;

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

char **ft_param(char *arv)
{
	int i;
	char **param;

	i = 0;
	param = ft_split(arv, ' ');
	return (param);
}

int main(int arc, char *arv[], char *env[])
{
	int	fd[2];
	t_pipe	pp;
	(void)arc;

	pp.name_file = arv[1];
	pp.fd_file = open(pp.name_file, O_RDONLY ,0644);
	if (pp.fd_file == -1)
		ft_exit();
	if (pipe(fd) == -1)
		ft_exit();
	pp.fr1 = fork();
	if (pp.fr1 == -1)
		ft_exit();
	
	if (pp.fr1 == 0) 
	{    
		pp.param = ft_param(arv[2]);
		pp.url= ft_url(ft_path(env), pp.param[0]);
		if (pp.url == 	NULL)
			ft_exit();
		dup2(pp.fd_file, 0);
		dup2(fd[1], 1);
		close(fd[1]);
		close(fd[0]);
		if (execve(pp.url, pp.param, env) < 0)
			exit(0);
	}
	if (pp.fr1 != 0)
		pp.fr2 = fork();
	if (pp.fr2 == -1)
		ft_exit();
	if (pp.fr2 == 0)
	{
		pp.param = ft_param(arv[3]);
		pp.url = ft_url(ft_path(env), pp.param[0]);
		if (pp.url == NULL)
			ft_exit();
		pp.fd2_file = open(arv[4],  O_CREAT | O_RDWR, 0644);
		if (pp.fd2_file == -1)
			exit(0);
		dup2(pp.fd2_file, 1);
		dup2(fd[0], 0);
		close(fd[1]);
		close(fd[0]);
		if (execve(pp.url, pp.param, env) < 0)
			exit(0);
	}
		close(fd[1]);
		close(fd[0]);
		while (wait(NULL) != -1);
}