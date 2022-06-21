/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 16:38:25 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/20 17:35:24 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <stdio.h>

int	main(int arc, char *arv[], char *env[])
{
	t_pipe	pp;

	if (ft_strncmp(arv[1], "here_doc", ft_strlen(arv[1])) == 0
		&& ft_strlen(arv[1]) == ft_strlen("here_doc"))
	{
		pp.nb_pipe = arc - 4;
		ft_here_doc(&pp, arv);
		ft_pipe(&pp);
		ft_open_files_here(&pp, arv, arc);
		ft_main_fork_here(&pp, arc, arv, env);
		close(pp.pipe_here[1]);
		close(pp.pipe_here[0]);
		ft_close(&pp);
		ft_wait(&pp);
	}
	else
	{
		pp.nb_pipe = arc - 3;
		ft_pipe(&pp);
		ft_open_files(&pp, arv, arc);
		ft_main_fork(&pp, arc, arv, env);
		ft_close(&pp);
		ft_wait(&pp);
	}
	return (0);
}
