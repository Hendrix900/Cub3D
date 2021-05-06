/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 05:41:25 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/06 23:01:18 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	free_print_error(char *s)
{
	g_check.error = 1;
	g_check.error_line = s;
}
