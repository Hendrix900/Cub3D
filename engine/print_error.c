/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 05:41:25 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:16:12 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_print_error(char *s, t_cub *cub)
{
	cub->cf.error = 1;
	cub->cf.error_line = s;
}

void	print_error(char *s, t_cub *cub)
{
	char	*s2;

	free_split(cub->cf.map);
	if (cub->cf.param_ea)
		free(cub->cf.texture_ea);
	if (cub->cf.param_no)
		free(cub->cf.texture_no);
	if (cub->cf.param_so)
		free(cub->cf.texture_so);
	if (cub->cf.param_we)
		free(cub->cf.texture_we);
	if (cub->cf.param_s)
		free(cub->cf.texture_s);
	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	print_error_arg(char *s)
{
	char	*s2;

	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	print_error_window(char *s, t_cub *cub)
{
	char	*s2;

	free_split(cub->cf.map);
	free(cub->cf.texture_ea);
	free(cub->cf.texture_no);
	free(cub->cf.texture_so);
	free(cub->cf.texture_we);
	free(cub->cf.texture_s);
	mlx_destroy_display(cub->mlx.ptr);
	free(cub->mlx.ptr);
	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

void	print_error_image(char *s, t_cub *cub)
{
	char	*s2;

	free_split(cub->cf.map);
	free(cub->cf.texture_ea);
	free(cub->cf.texture_no);
	free(cub->cf.texture_so);
	free(cub->cf.texture_we);
	free(cub->cf.texture_s);
	mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
	mlx_destroy_display(cub->mlx.ptr);
	free(cub->mlx.ptr);
	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}
