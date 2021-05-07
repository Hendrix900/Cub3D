/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:37:46 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/07 19:34:37 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_rgb_range(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	{
		if (g_check.error != 1)
			free_print_error("Some RGB number is out of range");
	}
}

void	check_len_color(char *position)
{
	int l;
	int count;

	count = 0;
	l = 0;
	if (position[l + 1] != ' ' && position[l + 1] != '\t' && g_check.error != 1)
		free_print_error("Wrong character at the beginign of some color line");
	while (position[l] != '\0')
	{
		if (ft_strchr("FC\t ,", position[l]))
			l++;
		else if ((position[l] >= 48) && (position[l] <= 57))
		{
			while ((position[l] >= 48) && (position[l] <= 57))
				l++;
			count++;
		}
		else
			l++;
	}
	if (count != 3 && g_check.error != 1)
		free_print_error("The number of colors arguments are wrong");
}

int		check_color(char *position, char *line)
{
	int count;
	int l;

	count = 0;
	l = 0;
	while (line[l] != '\0')
	{
		if (line[l] == 'F' || line[l] == 'C')
			count++;
		l++;
	}
	if (count != 1 && g_check.error != 1)
		free_print_error("Wrong color line");
	l = 0;
	while (position[l] != '\0')
	{
		if (!(ft_strchr("0123456789FC\t ,", position[l])) && g_check.error != 1)
			free_print_error("Wrong characters in color line");
		if (ft_strchr(",", position[l]))
			count++;
		l++;
	}
	if (count != 3 && g_check.error != 1)
		free_print_error("The number of colors or comas in line are wrong");
	return (0);
}

void	extract_color_floor(char *line, char *position)
{
	check_line_before_parameter(position, line);
	check_color(position, line);
	check_len_color(position);
	if (g_check.error != 1)
	{
		position++;
		check_position_color(position);
		g_check.floor_r = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position);
		g_check.floor_g = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position);
		g_check.floor_b = ft_atoi(position);
		check_rgb_range(g_check.floor_r, g_check.floor_g, g_check.floor_b);
		g_check.rgb_f = rgb_conver(0, g_check.floor_r, g_check.floor_g,
		g_check.floor_b);
	}
	g_check.count_parameters++;
}

void	extract_color_celing(char *line, char *position)
{
	check_line_before_parameter(position, line);
	check_color(position, line);
	check_len_color(position);
	if (g_check.error != 1)
	{
		position++;
		check_position_color(position);
		g_check.celing_r = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position);
		g_check.celing_g = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position);
		g_check.celing_b = ft_atoi(position);
		check_rgb_range(g_check.celing_r, g_check.celing_g, g_check.celing_b);
		g_check.rgb_c = rgb_conver(0, g_check.celing_r, g_check.celing_g,
		g_check.celing_b);
	}
	g_check.count_parameters++;
}
