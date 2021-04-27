/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:38:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/27 17:09:50 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		count_split(char **str, int rows)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (i != rows)
		print_error("Incorrect number of arguments");
	return (i);
}

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

int		rgb_conver(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
