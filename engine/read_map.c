/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 01:18:39 by carlos            #+#    #+#             */
/*   Updated: 2021/04/30 18:10:34 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_spacestr(int len)
{
	char	*new;
	int		l;

	l = 0;
	new = (char*)malloc(sizeof(char) * (len + 1));
	while (l < len)
	{
		new[l] = ' ';
		l++;
	}
	new[l] = '\0';
	return (new);
}

void	complete_map(void)
{
	int			i;
	ssize_t		dif;
	char		*join;
	char		*space;

	i = 0;
	while (g_check.map[i])
	{
		if (dif = g_check.n_columns - ft_strlen(g_check.map[i]))
		{
			space = ft_spacestr(dif);
			join = ft_strjoin(g_check.map[i], space);
			free(g_check.map[i]);
			g_check.map[i] = join;
			free(space);
		}
		i++;
	}
}

void	check_line_map(char *line)
{
	int		l;
	char	*swap;

	l = 0;
	if (g_check.buffer == NULL)
		g_check.buffer = ft_strdup("");
	while (line[l] != '\0')
	{
		if (!(ft_strchr("NESW012 ", line[l])))
			print_error("Wrong character in map or parameter repeated");
		l++;
	}
	swap = ft_strjoin(g_check.buffer, line);
	free(g_check.buffer);
	g_check.buffer = swap;
	swap = ft_strjoin(g_check.buffer, "\n");
	free(g_check.buffer);
	g_check.buffer = swap;
	if (g_check.n_columns < l)
		g_check.n_columns = l;
}

void	read_map(int fd, char *line)
{
	char	dev;
	int		l;

	l = 0;
	check_line_map(line);
	free(line);
	while (dev = get_next_line(fd, &line) > 0)
	{
		check_line_map(line);
		free(line);
	}
	check_line_map(line);
	free(line);
	close(fd);
	g_check.map = ft_split(g_check.buffer, '\n');
	free(g_check.buffer);
	complete_map();
	read_moremap();
}
