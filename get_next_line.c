/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouazzan <iouazzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 05:02:05 by iouazzan          #+#    #+#             */
/*   Updated: 2021/12/09 02:30:41 by iouazzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	size_t	i;

	i = 0;
	c = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!c)
		return (NULL);
	while (s1[i])
	{
		c[i] = s1[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new[i] = *s2;
		i++;
		s2++;
	}
	new[i] = '\0';
	free((void *)s1);
	return (new);
}

char	*ft_line(int fd, char **backup)
{
	char	*buffer;
	char	*line;
	ssize_t	rt_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!(*backup))
		line = ft_strdup("");
	else
		line = ft_strdup(*backup);
	while (ft_strchr(line, '\n') == NULL)
	{
		rt_read = read(fd, buffer, BUFFER_SIZE);
		if (rt_read < 0)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		if (rt_read == 0)
			break ;
		buffer[rt_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*ft_return(char **line, char **buckup)
{
	char	*tmp;

	tmp = ft_substr(*line, 0, ft_strchr(*line, '\n') - *line + 1);
	*buckup = ft_substr(*line, ft_strchr(*line, '\n') - *line + 1, -1);
	if (*buckup && **buckup == '\0')
	{
		free (*buckup);
		*buckup = NULL;
	}
	free (*line);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_line(fd, &backup[fd]);
	if (backup[fd])
	{
		free (backup[fd]);
		backup[fd] = NULL;
	}
	if (!line)
		return (NULL);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	if (ft_strchr(line, '\n') == 0)
		return (line);
	return (ft_return(&line, &backup[fd]));
}
