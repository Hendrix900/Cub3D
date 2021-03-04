/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:38:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/04 04:19:58 by ccastill         ###   ########.fr       */
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
