/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/11 08:44:47 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_path(char *path, char *position, char *line)
{
	int		l;
	int		dif;

	l = 0;
	dif = ft_strlen(line) - ft_strlen(position);
	if (dif)
	{
		while (l < dif)
		{
			if (line[l] > 33 && line[l] < 126)
				print_error("wrong characters in some texture line");
			l++;
		}
	}
	return (0);
}

char	*extract_texture(char *line, char *position)
{
	char	**split;
	char	*path;

	split = ft_split(position, ' ');
	count_split(split, 2);
	path = ft_strdup(split[1]);
	check_path(path, position, line);
	free_str(split);
	g_check.count_parameters++;
	return (path);
}
