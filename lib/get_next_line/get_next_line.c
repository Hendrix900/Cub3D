/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:17:01 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/06 08:27:40 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_line(char **line, char **s)
{
	int		count;
	char	*tmp;

	count = 0;
	while ((*s)[count] != '\n' && (*s)[count] != '\0')
		count++;
	if ((*s)[count] == '\n')
	{
		*line = ft_substr(*s, 0, count);
		tmp = ft_strdup(&(*s)[count + 1]);
		free(*s);
		*s = tmp;
	}
	else if ((*s)[count] == '\0')
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

static int	ft_check(char **s, int bwr, int fd, char **line)
{
	if (bwr < 0)
		return (-1);
	else if (bwr == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		free(*s);
		*s = NULL;
		return (0);
	}
	else
		return (ft_line(line, &s[fd]));
}

int			get_next_line(int fd, char **line)
{
	static char	*s[4096];
	int			bwr;
	char		*buff;
	char		*temp;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		|| fd < 0 || line == 0)
		return (-1);
	while ((bwr = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[bwr] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			temp = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buff);
	buff = NULL;
	return (ft_check(s, bwr, fd, line));
}
