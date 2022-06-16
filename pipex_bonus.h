/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:24:29 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/16 14:15:30 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct t_pipe
{
	char	*url;
	int		fd[2];
	char	**param;
	int		fd_file;
	int		fd_file_2;
	int		fd_last_file;
	char	*name_file;
	char	*name_file_2;
	int		i;
	int		j;
	int		*fr;
	int		nb_pipe;
	int		nb_fork;
	int		fr1;

}	t_pipe;

char		*ft_url_bonus(char *path, t_pipe *pp);
char		*ft_path_bonus(char *env[]);
void		ft_param_bonus(char *arv[], t_pipe *pp, int arc);
int			ft_exit_bonus(void);
void		ft_fork_last_bonus(t_pipe *pp, char arv[], char *env[]);
void		ft_fork_bonus(t_pipe *pp, char *arv[], char *env[], int *fd_pipe[], int arc);
t_pipe		*ft_fd_pipe(t_pipe *pp);
int			ft_exit_bonus(void);
void		ft_cmnd(t_pipe *pp, char arv[], char *env[]);

#endif