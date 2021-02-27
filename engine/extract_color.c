/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 03:37:46 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/27 04:12:18 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		extract_color(char *line, char *position)
{
	char **split;
	split = ft_split(position,' ');
	check_len(split, 4);
	g_check.floor_r = ft_atoi(split[1]);
	g_check.floor_g = ft_atoi(split[2]);
	g_check.floor_b = ft_atoi(split[3]);
	/*
	if (!(g_check.resolution_width = ft_atoi(split[1])) || // Si no puede realizar el atoi. pasar de cadena a entero, lánzame el error.
	(!(g_check.resolution_hight = ft_atoi(split[2]))))
		print_error("Introducido caracteres donde deberían ir números");
	*/
}