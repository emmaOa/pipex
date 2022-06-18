/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:24:29 by iouazzan          #+#    #+#             */
/*   Updated: 2022/06/18 01:36:26 by iouazzan         ###   ########.fr       */
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

typedef struct s_pipe
{
	char	*url;
	char	*tmp;
	int		**fd_pipe;
	int		fd_tmp_file;
	int		*pipe_here;
	char	**param;
	int		fd_file_2;
	int		fd_last_file;
	char	*name_file_2;
	int		fd_file;
	int		fr1;
	int		*fr;
	char	*name_file;
	int		nb_pipe;
	int		nb_fork;
	int		i;
	int		j;
}			t_pipe;

char		*ft_url_bonus(char *path, t_pipe *pp);
char		*ft_path_bonus(char *env[]);
void		ft_param_bonus(char *arv[], t_pipe *pp, int arc);
int			ft_exit_bonus(void);
void		ft_fork_bonus(t_pipe *pp, char *arv[], char *env[]);
void		ft_open_files(t_pipe *pp, char *arv[], int arc);
void		ft_main_fork(t_pipe *pp, int arc, char *arv[], char *env[]);
void		ft_open_files_here(t_pipe *pp, char *arv[], int arc);
void		ft_main_fork_here(t_pipe *pp, int arc, char *arv[], char *env[]);
void		ft_fork_here(t_pipe *pp, char *arv[], char *env[]);
void		ft_foork_bonus_here(t_pipe *pp);
void		ft_pipe(t_pipe *pp);
t_pipe		*ft_fd_pipe(t_pipe *pp);
int			ft_exit_bonus(void);
void		ft_wait(t_pipe *pp);
void		ft_close(t_pipe *pp);

#endif