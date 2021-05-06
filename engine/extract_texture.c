/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 02:29:00 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/06 23:15:01 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_character_after_len(char *position, int l)
{
	while (position[l] != '\0')
	{
		if ((position[l] != ' ') && (position[l] != '\t') && g_check.error != 1)
			free_print_error("Wrong character at the end of some texture path");
		l++;
	}
}

int		check_len_texture(char *position, int len)
{
	int		save;

	save = 0;
	while (position[len] != '\0')
	{
		if ((position[len] == ' ') || (position[len] == '\t'))
		{
			check_character_after_len(position, len);
			return (len);
		}
		len++;
	}
	return (len);
}

char	*check_path_texture(char *line, char *position, int l)
{
	int		count;
	char	*new;
	int		diference;

	count = 0;
	if (position[l] != ' ' && position[l] != '\t' && g_check.error != 1)
		free_print_error("Some texture line is wrong");
	while (position[l] != '\0')
	{
		if ((position[l] == '.') && (position[l + 1] == '/'))
		{
			diference = check_len_texture(position, l) - l;
			new = ft_substr(position, l, diference);
			count++;
		}
		if ((position[l] != ' ') && (position[l] != '\t') && (count == 0) &&
			g_check.error != 1)
			free_print_error("Wrong characters in some texture line");
		if (position[l] != '\0')
			l++;
	}
	return (new);
}

char	*extract_texture(char *line, char *position)
{
	char	*path;
	char	*dev;
	int		l;

	l = 2;
	check_line_before_parameter(position, line);
	path = check_path_texture(line, position, l);
	g_check.count_parameters++;
	return (path);
}

char	*extract_texture_sprite(char *line, char *position)
{
	char	*path;
	char	*dev;
	int		l;

	l = 1;
	check_line_before_parameter(position, line);
	path = check_path_texture(line, position, l);
	g_check.count_parameters++;
	return (path);
}
