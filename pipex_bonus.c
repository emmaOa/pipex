/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:51:01 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/16 16:10:46 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

char		*ft_url_bonus(char *path, t_pipe *pp)
{
	int i;
	char **tmp;

	i = 0;
	tmp = ft_split(path, ':');
	// for (int m = 0 ; m < 5; m++){
	// 	printf("%s\n", tmp[m]);
	// }
	while (tmp[i])
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		tmp[i] = ft_strjoin(tmp[i], pp->param[0]);
		if (access(tmp[i], F_OK) == 0)
			return(tmp[i]);
		i++;
	}
	return (NULL);
}

// char	*ft_url_bonus(char *path, t_pipe *pp)
// {
// 	int		i;
// 	char	**url;
// 	char	*cmd_path;

// 	i = 0;
// 	url = ft_split(path, ':');

// 	while (pp->param[i] != NULL)
// 		i++;
// 	while (url[i])
// 	{
// 		cmd_path = ft_strjoin(url[i], "/");
// 		cmd_path = ft_strjoin(cmd_path, pp->param[0]);
// 		if (access(cmd_path, F_OK) == 0)
// 			return (cmd_path);
// 		i++;
// 	}
// 	return (NULL);
// }

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

// void	ft_param_bonus(char *arv[], t_pipe *pp, int arc)
// {

// 	// int i;
// 	// int x;
// 	// int r = 0;
// 	// int nb = 0;

// 	// i = 2;
// 	// x = 0;

// 	// while (arv[pp->i][r])
// 	// {
// 	// 	if (arv[pp->i][r] == ' ' && arv[pp->i][r + 1] != ' ')
// 	// 	{
// 	// 		printf("check\n");
// 	// 		printf("space %d\n", nb);
// 	// 		nb++;
// 	// 	}
// 	// 	r++;
// 	// }
		

// 	// printf("%d\n", nb);
// 	// pp->param = (char **)malloc(nb + 1 * sizeof(char *));
// 	// while (x < nb + 1 )
// 	// {
//     //    pp->param[x] = (char *)malloc((strlen(arv[i]) + 1) * sizeof(char));
// 	// 	x++;
// 	// 	i++;
// 	// }
// 	pp->param = ft_split(arv[arc - 4 + pp->i], ' ');
// 	// for (int l = 0; l < 2; l++)
// 	// {
// 	// 	printf("%s  \n", pp->param[l]);

// 	// }
// 	// exit(1);
// 	// i = 2;
// 	// x = 0;
// 	// while (i < arc - 1)
// 	// {

// 	// 	pp->param[x] = ft_strdup(arv[i]);
// 	// 	i++;
// 	// 	x++;
// 	// }

// }



int main(int arc, char *arv[], char *env[])
{
	t_pipe	pp;
	int j;
 	int		**fd_pipe;
	int		x;
 
	x = 0;
	(void)env;
	pp.i = 0;
	pp.nb_fork = arc - 3;
	pp.nb_pipe = pp.nb_fork + 1;
	pp.name_file = arv[1];
	fd_pipe = (int **)malloc(pp.nb_pipe * sizeof(int *));
	while (x < pp.nb_pipe)
	{
       fd_pipe[x] = (int *)malloc(2 * sizeof(int));
		x++;
	}
	pp.fr = (int *)malloc(pp.nb_fork * sizeof(int));
	pp.fd_file = open(pp.name_file, O_RDONLY, 0644);
	if (pp.fd_file == -1)
		exit(1);
	pp.name_file_2 = arv[arc - 1];
	pp.fd_file_2 = open(pp.name_file_2, O_CREAT | O_RDWR, 0644);
	if (pp.fd_file_2 == -1)
		exit(1);
	while (pp.i < pp.nb_pipe)
	{
		if (pipe(fd_pipe[pp.i]) == -1)
			return 1; 
		pp.i++;
	}
	pp.i = 0;
	
	while (pp.i < pp.nb_fork)
	{
		pp.fr[pp.i] = fork();
		if (pp.fr[pp.i] == -1)
			return 2;
		if (pp.fr[pp.i] == 0)
		{
			pp.j = 0;
			while (pp.j< pp.nb_pipe)
			{
				if (pp.i != pp.j)
					close(fd_pipe[pp.j][0]);
				if (pp.i + 1 != pp.j)
					close(fd_pipe[pp.j][1]);
				pp.j++;
			}
			ft_fork_bonus(&pp, arv, env, fd_pipe, arc);
			printf("jj\n");
			return (0);
		}
		pp.i++;
	}
	j = 0;
	while (j < pp.nb_pipe)
	{
		if (j != pp.nb_fork)
			close(fd_pipe[j][0]);
		if (j != 0)
			close(fd_pipe[j][1]);
		j++;
	}
	dup2(pp.fd_file, 0);
	dup2(pp.fd_file_2, fd_pipe[pp.i][1]);
	close(fd_pipe[pp.nb_fork][0]);
	close(fd_pipe[0][1]);
	j = 0;
	while (j < pp.nb_fork)
	{
		wait(NULL);
		j++;
	}
	return (0);

}