#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <unistd.h>
#include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct t_pipe
{
	int		fr1;
	int		fr2;
	char	*url;
	char	**param;
	int		fd_file;
	int		fd2_file;
	char	*name_file;

}	t_pipe;

int	ft_exit(void);
char	*ft_url(char *path, char *comnd);
char *ft_path(char *env[]);
char **ft_param(char *arv);
#endif
