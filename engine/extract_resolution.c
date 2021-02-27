/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 21:54:22 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/27 02:41:58 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	extract_resolution(char *line, char *position)
{
	char **split;
	split = ft_split(position,' ');
	check_len(split, 3);
	if (!(g_check.resolution_width = ft_atoi(split[1])) || // Si no puede realizar el atoi. pasar de cadena a entero, lánzame el error.
	(!(g_check.resolution_hight = ft_atoi(split[2]))))
		print_error("Introducido caracteres donde deberían ir números");
	if (g_check.resolution_width > 1920 || g_check.resolution_hight > 1080)
	{
		g_check.resolution_width = 1920;
		g_check.resolution_hight = 1080;
	}
	if (g_check.resolution_width < 320 || g_check.resolution_hight < 200)
	{
		g_check.resolution_width = 320;
		g_check.resolution_hight = 200;
	}
}