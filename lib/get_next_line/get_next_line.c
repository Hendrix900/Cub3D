/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:17:01 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:17:30 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//REVISADA POR NUEVA NORMINETTE V3

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

void	get_next_join(int fd, char **s, char *buff)
{
	char	*temp;

	temp = ft_strjoin(s[fd], buff);
	free(s[fd]);
	s[fd] = temp;
}

int	get_next_line(int fd, char **line)
{
	static char	*s[4096];
	int			bwr;
	char		*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!(buff) || fd < 0 || line == 0)
		return (-1);
	bwr = 1;
	while (bwr > 0)
	{
		bwr = read(fd, buff, BUFFER_SIZE);
		buff[bwr] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			get_next_join(fd, s, buff);
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	free(buff);
	return (ft_check(s, bwr, fd, line));
}
