#include "pipex.h"
#include <stdio.h>

int	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit (1);
}

int	ft_url(char *path, char *comnd)
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
			return (1);
		i++;
	}
	return (-1);
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
	int fd_file;
	int fd2_file;
	char *name_file;
	int	fd[2];
	char **param;
	int	fr1;
	int fr2;
	int url;
	(void)arc;

	name_file = arv[1];
	fd_file = open(name_file, O_RDONLY);
	if (open(name_file, O_RDONLY) == -1)
		perror ("open");
	if (pipe(fd) == -1)
		ft_exit();
	fr1 = fork();
	if (fr1 == -1)
		ft_exit();
	if (fr1 == 0) 
	{    
		param = ft_param(arv[2]);
		url= ft_url(ft_path(env), param[0]);
		if (url == -1)
			ft_exit();
		dup2(fd_file, fd[0]);
		dup2(fd_file, fd[1]);
		if (execve(param[0], param, env) < 0)
			exit(0);         
		close(fd[1]);
		close(fd[0]);             
	}
	fr2 = fork();
	if (fr2 == -1)
		ft_exit();
	if (fr2 == 0)
	{
		param = ft_param(arv[3]);
		url= ft_url(ft_path(env), param[0]);
		if (url == -1)
			ft_exit();
		// if (fd2_file = open(arv[4], O_RDWR  | O_CREAT) < 0)
		// 	exit(0);
		fd2_file = open(arv[4], O_RDWR | O_CREAT);
		if (fd2_file == -1)
			exit(0);
		dup2(fd2_file, 1);
		dup2(fd2_file, 0);
		if (execve(param[0], param, env) < 0)
			exit(0);
		close(fd[1]);
		close(fd[0]);   
	}
		wait(NULL);
		close(fd[1]);
		close(fd[0]);
}