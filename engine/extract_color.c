/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:37:46 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/28 00:13:29 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//Modificar
void check_rgb_range(int r, int g, int b)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
		print_error("Some RGB parameter is out of range");
}

int check_coma(char **split, char *position)
{
	int counter;	
	int l;
	int i;

	l = 0;
	i = 0;
	counter = 0;
	while (position[l] != '\0')
		{
			if (!(ft_strchr("0123456789FC ,", position[l])))
				print_error("Wrong colors");
			if (ft_strchr(",", position[l]))
				counter++;
			if (ft_strnstr(split[3], ",", ft_strlen(split[3])))				
				print_error("EL tercer parámetro no lleva coma");
		l++;
		}
	if (counter != 2)
		print_error("Number of colors are incorrect");
	return (0);
}

void extract_color(char *line, char *position)
{
	char **split;
	int counter;
	split = ft_split(position, ' ');
	check_len(split, 4);
	check_coma(split, position);
	if (ft_strnstr(split[0], "F", ft_strlen(split[0])))
	{
		if ((!(g_check.floor_r = ft_atoi(split[1]))) ||
			(!(g_check.floor_g = ft_atoi(split[2]))) ||
			(!(g_check.floor_b = ft_atoi(split[3]))))
			print_error("Wrong colors!");
		check_rgb_range(g_check.floor_r, g_check.floor_g, g_check.floor_b);
	}
	else if (ft_strnstr(split[0], "C", ft_strlen(split[0])))
	{
		if ((!(g_check.celing_r = ft_atoi(split[1]))) ||
			(!(g_check.celing_g = ft_atoi(split[2]))) ||
			(!(g_check.celing_b = ft_atoi(split[3]))))
			print_error("Wrong colors!");
		check_rgb_range(g_check.celing_r, g_check.celing_g, g_check.celing_b);
	}
}