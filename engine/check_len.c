/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 00:38:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/01 19:35:34 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			check_len(char **aux, int num)
{
	int i;

	i = 0;
	while (aux[i] != NULL)
		i++;
	if (i != num)
		print_error("Error: Incorrect number of arguments");
	return (i);
}