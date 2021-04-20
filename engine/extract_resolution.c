/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:54:22 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/20 15:59:56 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_resolution(char *line)
{
	int l;
	int count;

	l = 0;
	count = 0;
	while (line[l] != '\0')
	{
		if (!(ft_strchr("0123456789R ", line[l])))
			print_error("Wrong resolution path");
		if (line[l] == 'R')
			count++;
		l++;
	}
	if (count != 1)
		print_error("Wrong resolution path");
}

void	extract_resolution(char *line, char *position)
{
	char **split;
	
	check_path(position, line);
	check_resolution(line);
	split = ft_split(position, ' ');
	count_split(split, 3);
	if (!(g_check.res_w = ft_atoi(split[1])) ||
		(!(g_check.res_h = ft_atoi(split[2]))))
		print_error("Wrong resolution number");
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
	free_str(split);
	g_check.count_parameters++;
}
