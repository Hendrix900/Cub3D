/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 05:41:25 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/07 23:59:01 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_print_error(char *s)
{
	g_check.error = 1;
	g_check.error_line = s;
}

void	print_error(char *s)
{
	char *s2;

	free_split(g_check.map);
	free(g_check.texture_ea);
	free(g_check.texture_no);
	free(g_check.texture_so);
	free(g_check.texture_we);
	free(g_check.texture_s);
	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	print_error_arg(char *s)
{
	char *s2;

	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	print_error_window(char *s, t_cub *cub)
{
	char *s2;

	free_split(g_check.map);
	free(g_check.texture_ea);
	free(g_check.texture_no);
	free(g_check.texture_so);
	free(g_check.texture_we);
	free(g_check.texture_s);
	mlx_destroy_display(cub->mlx.ptr);
	free(cub->mlx.ptr);
	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	print_error_image(char *s, t_cub *cub)
{
	char *s2;

	free_split(g_check.map);
	free(g_check.texture_ea);
	free(g_check.texture_no);
	free(g_check.texture_so);
	free(g_check.texture_we);
	free(g_check.texture_s);
	mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
	mlx_destroy_display(cub->mlx.ptr);
	free(cub->mlx.ptr);
	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}
