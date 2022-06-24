/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 02:14:08 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/21 04:45:33 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct t_pipe
{
	int		fr1;
	int		fr2;
	char	*url;
	int		fd[2];
	char	**param;
	int		fd_file;
	int		fd2_file;
	char	*name_file;

}	t_pipe;

void	ft_exit(char *s, t_pipe *pp);
char	*ft_url(char *path, char *comnd);
char	*ft_path(char *env[]);
char	**ft_param(char *arv);
void	ft_fork_1(t_pipe *pp, char *arv[], char *env[]);
void	ft_fork_2(t_pipe *pp, char *arv[], char *env[]);
void	ft_free(char **tabl, int start, int len);
int		ft_len(char **tabl);
#endif
