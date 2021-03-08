/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 20:05:23 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/08 07:53:01 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_line3(char *line, char *position, int l)
{
	if ((position = ft_strnstr(line, "F ", ft_strlen(line))) &&
	g_check.param_f == 0)
	{
		extract_color_floor(line, position);
		g_check.param_f = 1;
		return (0);
	}
	else if ((position = ft_strnstr(line, "C ", ft_strlen(line))) &&
	g_check.param_c == 0)
	{
		extract_color_celing(line, position);
		g_check.param_c = 1;
		return (0);
	}
	else
	{
		while (line[l] != '\0')
		{
			if (!(ft_strchr(" ", line[l])))
				print_error("Wrong number of parameters");
			l++;
		}
	}
}

int		check_line2(char *line, char *position, int l)
{
	if ((position = ft_strnstr(line, "WE ", ft_strlen(line))) &&
	g_check.param_we == 0)
	{
		g_check.texture_we = extract_texture(line, position);
		g_check.param_we = 1;
		return (0);
	}
	else if ((position = ft_strnstr(line, "EA ", ft_strlen(line))) &&
	g_check.param_ea == 0)
	{
		g_check.texture_ea = extract_texture(line, position);
		g_check.param_ea = 1;
		return (0);
	}
	else if ((position = ft_strnstr(line, "S ", ft_strlen(line))) &&
	g_check.param_s == 0)
	{
		g_check.texture_s = extract_texture(line, position);
		g_check.param_s = 1;
		return (0);
	}
	check_line3(line, position, l);
}

int		check_line(char *line, char *position, int l)
{
	if ((position = ft_strnstr(line, "R ", ft_strlen(line))) &&
	g_check.param_r == 0)
	{
		extract_resolution(line, position);
		g_check.param_r = 1;
		return (0);
	}
	else if ((position = ft_strnstr(line, "NO ", ft_strlen(line))) &&
	g_check.param_no == 0)
	{
		g_check.texture_no = extract_texture(line, position);
		g_check.param_no = 1;
		return (0);
	}
	else if ((position = ft_strnstr(line, "SO ", ft_strlen(line))) &&
	g_check.param_so == 0)
	{
		g_check.texture_so = extract_texture(line, position);
		g_check.param_so = 1;
		return (0);
	}
	check_line2(line, position, l);
}

void	read_file(char *argv)
{
	int		fd;
	char	*line;
	char	*position;
	int		l;

	l = 0;
	position = NULL;
	g_check.count_parameters = 0;
	if ((fd = open(argv, O_RDONLY)) <= 0)
		print_error("Is not possible to open the FD");
	while (get_next_line(fd, &line) > 0 && g_check.count_parameters < 8)
	{
		check_line(line, position, l);
		free(line);
	}
	if (g_check.count_parameters != 8)
		print_error("The number of elements in the file are wrong");
	read_map(fd, line);
}
