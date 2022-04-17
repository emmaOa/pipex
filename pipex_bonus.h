/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:24:29 by iouazzan          #+#    #+#             */
/*   Updated: 2022/04/17 05:08:49 by iouazzan         ###   ########.fr       */
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
	int		fd_last_file;
	char	*name_file;
	int		nb_cmnd;
	int		nb_pipe;
	int		fr1;
	int		**fd_pipe;
}	t_pipe;

char		*ft_url_bonus(char *path, char *comnd);
char		*ft_path_bonus(char *env[]);
char		**ft_param_bonus(char *arv);
int			ft_exit_bonus(void);
void		ft_fork_last_bonus(t_pipe *pp, char arv[], char *env[]);
void		ft_fork_1_bonus(t_pipe *pp, char *arv[], char *env[]);
t_pipe		*ft_fd_pipe(t_pipe *pp);
int			ft_exit_bonus(void);
void		ft_cmnd(t_pipe *pp, char arv[], char *env[]);

#endif