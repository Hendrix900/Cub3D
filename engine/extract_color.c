/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:37:46 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:15:45 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_rgb_range(int r, int g, int b, t_cub *cub)
{
	if (r > 255 || g > 255 || b > 255 || r < 0 || g < 0 || b < 0)
	{
		if (cub->cf.error != 1)
			free_print_error("Some RGB number is out of range", cub);
	}
}

void	check_len_color(char *position, t_cub *cub)
{
	int	l;
	int	count;

	count = 0;
	l = 0;
	if (position[l + 1] != ' ' && position[l + 1] != '\t' && cub->cf.error != 1)
		free_print_error("Wrong character at the beginign of color line", cub);
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
	if (count != 3 && cub->cf.error != 1)
		free_print_error("The number of colors arguments are wrong", cub);
}

int	check_color(char *position, char *line, t_cub *cub)
{
	int	count;
	int	l;

	count = 0;
	l = 0;
	while (line[l] != '\0')
	{
		if (line[l] == 'F' || line[l] == 'C')
			count++;
		l++;
	}
	if (count != 1 && cub->cf.error != 1)
		free_print_error("Wrong color line", cub);
	l = 0;
	while (position[l] != '\0')
	{
		if (!(ft_strchr("0123456789FC\t ,", position[l])) && cub->cf.error != 1)
			free_print_error("Wrong characters in color line", cub);
		if (ft_strchr(",", position[l]))
			count++;
		l++;
	}
	if (count != 3 && cub->cf.error != 1)
		free_print_error("Number of colors or comas in line are wrong", cub);
	return (0);
}

void	extract_color_floor(char *line, char *position, t_cub *cub)
{
	check_line_before_parameter(position, line, cub);
	check_color(position, line, cub);
	check_len_color(position, cub);
	if (cub->cf.error != 1)
	{
		position++;
		check_position_color(position, cub);
		cub->cf.floor_r = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position, cub);
		cub->cf.floor_g = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position, cub);
		cub->cf.floor_b = ft_atoi(position);
		check_rgb_range(cub->cf.floor_r, cub->cf.floor_g, cub->cf.floor_b, cub);
		cub->cf.rgb_f = rgb_conver(0, cub->cf.floor_r, cub->cf.floor_g,
				cub->cf.floor_b);
	}
	cub->cf.count_parameters++;
}

void	extract_color_celing(char *line, char *position, t_cub *cub)
{
	check_line_before_parameter(position, line, cub);
	check_color(position, line, cub);
	check_len_color(position, cub);
	if (cub->cf.error != 1)
	{
		position++;
		check_position_color(position, cub);
		cub->cf.celing_r = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position, cub);
		cub->cf.celing_g = ft_atoi(position);
		position = ft_strchr(position, ',');
		position++;
		check_position_color(position, cub);
		cub->cf.celing_b = ft_atoi(position);
		check_rgb_range(cub->cf.celing_r, cub->cf.celing_g, cub->cf.celing_b,
			cub);
		cub->cf.rgb_c = rgb_conver(0, cub->cf.celing_r, cub->cf.celing_g,
				cub->cf.celing_b);
	}
	cub->cf.count_parameters++;
}
