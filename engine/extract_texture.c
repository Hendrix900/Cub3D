/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/02 07:03:24 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_texture(char *path, char *xpm, char *png)
{
	int l;
	int i;

	l = 0;
	i = ft_strlen(path)-4;
	if ((path[0] != '.') && (path[1] != '/'))
		print_error("Wrong texture path");
	if (ft_strnstr(path, ".xpm", ft_strlen(path)))
	{
		while(path[i] != '\0')
		{
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
	}
}

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
	check_texture(path, xpm, png);
	free(split);
	g_check.count_parameters++;
	return (path);
}