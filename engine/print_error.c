/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 05:41:25 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/28 04:28:12 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error(char *s)
{
	char *s2;

	s2 = ft_strjoin("Error\n", s);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}

int		exit_game(t_cub *cub)
{
	mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
	exit(EXIT_SUCCESS);
	return (0);
}
