/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:38:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/02 04:29:59 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_split(char **str, int rows)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i != rows)
		print_error("Incorrect number of arguments");
	return (i);
}