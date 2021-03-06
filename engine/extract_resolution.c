/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:54:22 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:15:48 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_position_resolution(char *position, t_cub *cub)
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
	if (count != 2 && cub->cf.error != 1)
		free_print_error("Incorrect number of parameters in resolution", cub);
	return (h);
}

void	check_resolution(char *line, char *position, t_cub *cub)
{
	int		l;
	int		count;

	l = 0;
	count = 0;
	if (position[l + 1] != ' ' && position[l + 1] != '\t' && cub->cf.error != 1)
		free_print_error("Resolution line is wrong", cub);
	while (line[l] != '\0')
	{
		if (!(ft_strchr("0123456789R\t ", line[l])) && (cub->cf.error != 1))
			free_print_error("Wrong character in resolution line", cub);
		if (line[l] == 'R')
			count++;
		l++;
	}
	if (count != 1 && cub->cf.error != 1)
		free_print_error("Wrong resolution line", cub);
}

void	extract_resolution(char *line, char *position, t_cub *cub)
{
	char	**split;
	int		l;
	char	*new;

	l = 0;
	check_line_before_parameter(position, line, cub);
	check_resolution(line, position, cub);
	position++;
	cub->cf.res_w = ft_atoi(position);
	if (!(cub->cf.res_w) && (cub->cf.error != 1))
		free_print_error("Wrong resolution line", cub);
	l = check_position_resolution(position, cub);
	cub->cf.res_h = ft_atoi(position + l);
	if (!(cub->cf.res_h) && (cub->cf.error != 1))
		free_print_error("Wrong resolution line", cub);
	cub->cf.count_parameters++;
}
