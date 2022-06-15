/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utl_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 21:03:13 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/14 02:51:56 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int	ft_exit_bonus(void)
{
	write(2, "Error\n", 6);
	exit (1);
}



// void	ft_cmnd(t_pipe *pp, char arv[], char *env[])
// {
// 	pp->param = ft_param_bonus(arv, pp);
// 	pp->url = ft_url_bonus(ft_path_bonus(env), pp->param[0]);
// 	if (pp->url == NULL)
// 		ft_exit_bonus();
// }

void	ft_fork_bonus(t_pipe *pp, char *arv[], char *env[], int *fd_pipe[], int arc)
{
	
	ft_param_bonus(arv, pp, arc);
	// printf("%d\n", pp->i);
	pp->url = ft_url_bonus(ft_path_bonus(env), pp);
	exit(1);
	if (pp->url == NULL)
		ft_exit_bonus();
	dup2(fd_pipe[pp->i + 1][1], 1);
	dup2(fd_pipe[pp->i][0], 0);
	close(fd_pipe[pp->i][0]);
	close(fd_pipe[pp->i + 1][1]);
	printf("-----\n");
	if (execve(pp->url, pp->param, env) < 0)
		ft_exit_bonus();
}

// void	ft_fork_last_bonus(t_pipe *pp, char arv[], char *env[])
// {
// 	pp->param = ft_param_bonus(arv);
// 	pp->url = ft_url_bonus(ft_path_bonus(env), pp->param[0]);
// 	if (pp->url == NULL)
// 		ft_exit_bonus();
// 	pp->fd_last_file = open(arv, O_CREAT | O_RDWR, 0644);
// 	if (pp->fd_last_file == -1)
// 		ft_exit_bonus();
// 	dup2(pp->fd_last_file, 1);
// 	dup2(ppfd_pipe[pp->nb_pipe - 1][0], 0);
// 	close(pp->fd_pipe[pp->nb_pipe - 1][1]);
// 	close(pp->fd_pipe[pp->nb_pipe - 1][0]);
// 	if (execve(pp->url, pp->param, env) < 0)
// 		ft_exit_bonus();
// }

// t_pipe		*ft_fd_pipe(t_pipe *pp)
// {
// 	int i;

// 	i = 0;
// 	pp->fd_pipe = malloc(pp->nb_pipe * sizeof(int));
// 	while (i < pp->nb_pipe)
// 	{
// 		pp->fd_pipe[i] = malloc(2 * sizeof(int));
// 		if (pipe(pp->fd_pipe[i]) == -1)
// 			ft_exit_bonus();
// 		i++;
// 	}
// 	return (pp);
// }