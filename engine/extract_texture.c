/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/09 21:35:54 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_character_after_len(char *position, int l, t_cub *cub)
{
	while (position[l] != '\0')
	{
		if ((position[l] != ' ') && (position[l] != '\t') && cub->cf.error != 1)
			free_print_error("Wrong character at the end of some texture", cub);
		l++;
	}
}

int	check_len_texture(char *position, int len, t_cub *cub)
{
	int		save;

	save = 0;
	while (position[len] != '\0')
	{
		if ((position[len] == ' ') || (position[len] == '\t'))
		{
			check_character_after_len(position, len, cub);
			return (len);
		}
		len++;
	}
	return (len);
}

char	*check_path_texture(char *line, char *position, int l, t_cub *cub)
{
	int		count;
	char	*new;
	int		diference;

	count = 0;
	if (position[l] != ' ' && position[l] != '\t' && cub->cf.error != 1)
		free_print_error("Some texture line is wrong", cub);
	while (position[l] != '\0')
	{
		if ((position[l] != ' ') && (position[l] != '\t')
			&& (cub->cf.pathfound != 1))
		{
			cub->cf.pathfound = 1;
			diference = check_len_texture(position, l, cub) - l;
			new = ft_substr(position, l, diference);
			count++;
		}
		l++;
	}
	if (!(cub->cf.pathfound))
		new = ft_strdup("\0");
	return (new);
}

char	*extract_texture(char *line, char *position, t_cub *cub)
{
	char	*path;
	char	*dev;
	int		l;

	l = 2;
	cub->cf.pathfound = 0;
	check_line_before_parameter(position, line, cub);
	path = check_path_texture(line, position, l, cub);
	cub->cf.count_parameters++;
	return (path);
}

char	*extract_texture_sprite(char *line, char *position, t_cub *cub)
{
	char	*path;
	char	*dev;
	int		l;

	l = 1;
	cub->cf.pathfound = 0;
	check_line_before_parameter(position, line, cub);
	path = check_path_texture(line, position, l, cub);
	cub->cf.count_parameters++;
	return (path);
}
