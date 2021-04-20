/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/20 16:07:49 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*extract_texture(char *line, char *position)
{
	char	**split;
	char	*path;

	split = ft_split(position, ' ');
	count_split(split, 2);
	path = ft_strdup(split[1]);
	check_path(position, line);
	free_str(split);
	g_check.count_parameters++;
	return (path);
}
