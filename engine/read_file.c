/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 20:05:23 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/27 03:37:15 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	check_line3(char *line, char *position)
{
	if ((position = ft_strnstr(line, "F ", ft_strlen(line))) && 
	g_check.param_f == 0)
	{
		g_check.texture_f = extract_texture(line, position);
		g_check.param_f = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	else if ((position = ft_strnstr(line, "C ", ft_strlen(line))) && 
	g_check.param_c == 0)
	{
		g_check.texture_c = extract_texture(line, position);
		g_check.param_c = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}

	
}

void	check_line2(char *line, char *position)
{
	if ((position = ft_strnstr(line, "WE ", ft_strlen(line))) && 
	g_check.param_we == 0)
	{
		g_check.texture_we = extract_texture(line, position);
		g_check.param_we = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	else if ((position = ft_strnstr(line, "EA ", ft_strlen(line))) && 
	g_check.param_ea == 0)
	{
		g_check.texture_ea = extract_texture(line, position);
		g_check.param_ea = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	else if ((position = ft_strnstr(line, "S ", ft_strlen(line))) && 
	g_check.param_s == 0)
	{
		g_check.texture_s = extract_texture(line, position);
		g_check.param_s = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	check_line3(line, position);
}

void	check_line(char *line)
{
	char *position;
	char **split;
	if ((position = ft_strnstr(line, "R ", ft_strlen(line))) && 
	g_check.param_r == 0)
	{
		extract_resolution(line, position);
		g_check.param_r = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	if ((position = ft_strnstr(line, "NO ", ft_strlen(line))) && 
	g_check.param_no == 0)
	{
		g_check.texture_no = extract_texture(line, position);
		g_check.param_no = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	if ((position = ft_strnstr(line, "SO ", ft_strlen(line))) && 
	g_check.param_so == 0)
	{
		g_check.texture_so = extract_texture(line, position);
		g_check.param_so = 1; // Parametro que cuenta que la resolución ya se ha introducido
		g_check.count_parameters++; // Parámetro para contar el número de parámetros introducidos
	}
	check_line2(line, position);
}

void	read_file(char *argv)
{
	int fd;
	int i;
	g_check.count_parameters = 0;
	char *line;
	if ((fd = open(argv, O_RDONLY)) <= 0)
		print_error("Is not possible to open the FD");
	while (get_next_line(fd, &line) > 0 && g_check.count_parameters < 8) 
	{
		check_line(line);
		free(line);
	}
	if (g_check.count_parameters != 6)
		print_error("El número de parámetros introducidos no es el correcto");
}