/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:54:22 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/02 19:47:01 by ccastill         ###   ########.fr       */
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
	check_resolution(line);
	split = ft_split(position,' ');
	count_split(split, 3);

	if (!(g_check.resolution_width = ft_atoi(split[1])) ||
		(!(g_check.resolution_hight = ft_atoi(split[2]))))
		print_error("Wrong resolution number");
	if (g_check.resolution_width > 1920 || g_check.resolution_hight > 1080)
	{
		g_check.resolution_width = 1920;
		g_check.resolution_hight = 1080;
	}
	if (g_check.resolution_width < 320 || g_check.resolution_hight < 200)
	{
		g_check.resolution_width = 320;
		g_check.resolution_hight = 200;
	}
	free(split);
	g_check.count_parameters++;
}