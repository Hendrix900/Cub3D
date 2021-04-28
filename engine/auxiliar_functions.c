/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:38:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/29 01:44:05 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_str(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

int		check_path(char *position, char *line)
{
	int		l;
	int		dif;

	l = 0;
	dif = ft_strlen(line) - ft_strlen(position);
	if (dif)
	{
		while (l < dif)
		{
			if (line[l] > 33 && line[l] < 126)
				print_error("wrong characters at the beginning of some line");
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
	if (count == 0)
		print_error("Wrong character position in color");
}

int		rgb_conver(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
