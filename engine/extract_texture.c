/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/03 19:51:24 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_path(char *path, char *xpm, char *position, char *line)
{
	int l;
	int i;
	int count;

	l = 0;
	count = 0;
	i = ft_strlen(path)-4;
	if (!(path[0] == '.' && path[1] == '/'))
		print_error("Wrong texture path Inicio");
	l = 0;
	while (line[l] != '\0')
	{
		if (line[l] > 64 && line[l] < 91 )
			count++;
	l++;
	}
	if (position[0] == 'S' && position[1] == ' ' && count != 1)
			print_error("Wrong texture S");
	else if ((position[1] == 'A' || position[1] == 'E' || position[1] == 'O') 
			&& (count != 2))
		print_error("Wrong texture path demas parámetros");
}

/*	if (ft_strnstr(path, ".xpm", ft_strlen(path)))
	{
		while(path[i] != '\0')
		{&& count != 1
			if (xpm[l++] != path[i++])
				print_error("Wrong texture path");
		}
	}
	else
	{
		while(path[i] != '\0')
		{
			if (png[l++] != path[i++])
				print_error("Wrong texture path");
		}
	}*/

char	*extract_texture(char *line, char *position)
{
	char **split;
	char *path;
	char *xpm;
	char *png;
	
	xpm = ".xpm";
	png = ".png";
	split = ft_split(position, ' ');
	count_split(split, 2);
	path = ft_strdup(split[1]);
	check_path(path, xpm, position, line);
	free(split);
	g_check.count_parameters++;
	return (path);
}