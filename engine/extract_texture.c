/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/28 00:31:45 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char *extract_texture(char *line, char *position)
{
	char **split;
	char *path;
	split = ft_split(position, ' ');
	check_len(split, 2);
	path = ft_strdup(split[1]);
	free(split);
	return (path);
}