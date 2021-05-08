/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:54:22 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 03:36:54 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_position_resolution(char *position)
{
	int		l;
	int		h;
	int		count;

	l = 0;
	h = 0;
	count = 0;
	while (position[l] != '\0')
	{
		if ((position[l] > 47) && (position[l] < 58))
		{
			count++;
			while ((position[l] > 47) && (position[l] < 58))
			{
				l++;
			}
			if (count == 1)
				h = l;
		}
		if (position[l] != '\0')
			l++;
	}
	if (count != 2 && g_check.error != 1)
		free_print_error("Incorrect number of parameters in resolution line");
	return (h);
}

void	check_resolution(char *line, char *position)
{
	int		l;
	int		count;

	l = 0;
	count = 0;
	if (position[l + 1] != ' ' && position[l + 1] != '\t' && g_check.error != 1)
		free_print_error("Resolution line is wrong");
	while (line[l] != '\0')
	{
		if (!(ft_strchr("0123456789R\t ", line[l])) && (g_check.error != 1))
			free_print_error("Wrong character in resolution line");
		if (line[l] == 'R')
			count++;
		l++;
	}
	if (count != 1 && g_check.error != 1)
		free_print_error("Wrong resolution line");
}

void	extract_resolution(char *line, char *position)
{
	char	**split;
	int		l;
	char	*new;

	l = 0;
	check_line_before_parameter(position, line);
	check_resolution(line, position);
	position++;
	if (!(g_check.res_w = ft_atoi(position)) && (g_check.error != 1))
		free_print_error("Wrong resolution line");
	l = check_position_resolution(position);
	if (!(g_check.res_h = ft_atoi(position + l)) && (g_check.error != 1))
		free_print_error("Wrong resolution line");
	if (g_check.res_w > 1920 || g_check.res_h > 1080)
	{
		g_check.res_w = 1920;
		g_check.res_h = 1080;
	}
	if (g_check.res_w < 520 || g_check.res_h < 360)
	{
		g_check.res_w = 520;
		g_check.res_h = 360;
	}
	g_check.count_parameters++;
}
