/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 01:18:39 by carlos            #+#    #+#             */
/*   Updated: 2021/05/09 20:07:55 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_spacestr(int len)
{
	char	*new;
	int		l;

	l = 0;
	new = (char *)malloc(sizeof(char) * (len + 1));
	while (l < len)
	{
		new[l] = ' ';
		l++;
	}
	new[l] = '\0';
	return (new);
}

void	complete_map(t_cub *cub)
{
	int			i;
	ssize_t		dif;
	char		*join;
	char		*space;
	char		**map;

	i = 0;
	while (cub->cf.map[i])
	{
		dif = cub->cf.n_columns - ft_strlen(cub->cf.map[i]);
		if (dif)
		{
			space = ft_spacestr(dif);
			join = ft_strjoin(cub->cf.map[i], space);
			free(cub->cf.map[i]);
			cub->cf.map[i] = join;
			free(space);
		}
		i++;
	}
}

void	check_line_map(char *line, t_cub *cub)
{
	int		l;
	char	*swap;

	l = 0;
	if (cub->cf.buffer == NULL)
		cub->cf.buffer = ft_strdup("");
	while (line[l] != '\0')
	{
		if (!(ft_strchr("NESW012 ", line[l])) && (cub->cf.error != 1))
			free_print_error("Wrong character  or parameter in map", cub);
		l++;
	}
	swap = ft_strjoin(cub->cf.buffer, line);
	free(cub->cf.buffer);
	cub->cf.buffer = swap;
	swap = ft_strjoin(cub->cf.buffer, "\n");
	free(cub->cf.buffer);
	cub->cf.buffer = swap;
	if (cub->cf.n_columns < l)
		cub->cf.n_columns = l;
}

void	read_map(int fd, char *line, t_cub *cub)
{
	char	dev;
	int		l;

	l = 0;
	check_line_map(line, cub);
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		check_line_map(line, cub);
		free(line);
	}
	check_line_map(line, cub);
	free(line);
	close(fd);
	cub->cf.map = ft_split(cub->cf.buffer, '\n');
	free(cub->cf.buffer);
	complete_map(cub);
	if (cub->cf.error == 1)
		print_error(cub->cf.error_line, cub);
	read_moremap(cub);
}
