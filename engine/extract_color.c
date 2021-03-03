/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:37:46 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/03 19:51:14 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_rgb_range(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		print_error("Some RGB parameter is out of range");
}  

void check_len_color(char *position)
{
	int l;
	int count;

	count = 0;
	l = 0;
	while (position[l] != '\0')
		{
			if (ft_strchr("FC ,", position[l]))
				l++;
			else
			{
				while ((position[l] >= 48) && (position[l] <= 57))
					l++;
				count++;	
			}
		}
	if (count != 3)
		print_error("The number of colors arguments are wrong");
}

int check_color(char *position, char *line)
{
	int counter;
	int count;
	int l;
	int i;

	count = 0;
	l = 0;
	i = 0;
	counter = 0;
	while (line[l] != '\0')
	{
		if (line[l] == 'F' || line[l] == 'C')
			count++;
	l++;
	}
	if (count != 1)
		print_error("Wrong color path");
	l = 0;
	while (position[l] != '\0')
		{
			if (!(ft_strchr("0123456789FC ,", position[l])))
				print_error("Wrong colors");
			if (ft_strchr(",", position[l]))
				counter++;
		l++;
		}
	if (counter != 2)
		print_error("Number of colors are incorrect");
	return (0);
}

void	extract_color_floor(char *line, char *position)
{
	check_color(position, line);
	check_len_color(position);	
	position++;
	g_check.floor_r = ft_atoi(position);
	position = ft_strchr(position, ',');
	position++;
	g_check.floor_g = ft_atoi(position);
	position = ft_strchr(position, ',');
	position++;
	g_check.floor_b = ft_atoi(position);
	position = ft_strchr(position, ',');
	g_check.count_parameters++;
	check_rgb_range(g_check.floor_r, g_check.floor_g, g_check.floor_b);
}

void	extract_color_celing(char *line, char *position)
{
	check_color(position, line);
	check_len_color(position);	
	position++;
	g_check.celing_r = ft_atoi(position);
	position = ft_strchr(position, ',');
	position++;
	g_check.celing_g = ft_atoi(position);
	position = ft_strchr(position, ',');
	position++;
	g_check.celing_b = ft_atoi(position);
	g_check.count_parameters++;
	check_rgb_range(g_check.celing_r, g_check.celing_g, g_check.celing_b);
}