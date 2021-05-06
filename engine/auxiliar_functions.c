/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:38:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/06 19:07:19 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_line_before_parameter(char *position, char *line)
{
	int		l;
	int		dif;

	l = 0;
	dif = ft_strlen(line) - ft_strlen(position);
	if (dif)
	{
		while (l < dif)
		{
			if ((line[l] != ' ') && (line[l] != '\t') && (g_check.error != 1))
				free_print_error("wrong character before some parameter");
			l++;
		}
	}
	return (0);
}

void	check_position_color(char *position)
{
	int l;
	int	count;

	l = 0;
	count = 0;
	while (position[l] != ',' && position[l] != '\0')
	{
		if (position[l] > 47 && position[l] < 57)
			count++;
		l++;
	}
	if (count == 0 && g_check.error != 1)
		free_print_error("Wrong character in color line");
}

int		rgb_conver(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
