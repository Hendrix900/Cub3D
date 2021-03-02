/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/02 04:35:21 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *extract_texture(char *line, char *position)
{
	char **split;
	char *path;
	if (!(ft_strnstr(line, "./", ft_strlen(line))))
		print_error("Wrong texture path");
	if 	((!(ft_strnstr(line, ".xpm", ft_strlen(line)))) && // Cambiarlo
		(!(ft_strnstr(line, ".png", ft_strlen(line)))))
			print_error("Wrong texture path");
	split = ft_split(position, ' ');
	count_split(split, 2);
	path = ft_strdup(split[1]);
	free(split);
	g_check.count_parameters++;
	return (path);
}