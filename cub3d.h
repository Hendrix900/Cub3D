/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 06:18:44 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/17 20:41:43 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# define X_EXIT 17

#include <X11/Xlib.h>
#include "./lib/mlx/minilibx-linux/mlx.h"
#include "./lib/libft/libft.h"
#include "./lib/get_next_line/get_next_line.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

typedef struct	s_check // Estructura de chequeo de variables
{
	int			img_save;



}				t_check;
t_check		g_check; // Declaración de la estructura


typedef struct	s_engine
{


}				t_engine;

void	print_error(char *s);
void	read_file(char *argv);


#endif
