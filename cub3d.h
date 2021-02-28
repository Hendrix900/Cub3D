/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 06:18:44 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/28 03:21:41 by carlos           ###   ########.fr       */
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
	int			resolution_width;
	int			resolution_hight;

	///Contador de parámetros///
	int			count_parameters;
	int			param_r;
	int			param_no;
	int			param_so;
	int			param_we;
	int			param_ea;
	int			param_s;
	int			param_f;
	int			param_c;

	///Texturas///
	char		*texture_no;
	char		*texture_so;
	char		*texture_we;
	char		*texture_ea;
	char		*texture_s;
	

	///Colors///
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			celing_r;
	int			celing_g;
	int			celing_b;

	///Columnas///
	int			n_columns;
	int			n_rows;

	


	


}				t_check;
t_check		g_check; // Declaración de la estructura


typedef struct	s_engine
{


}				t_engine;

void	print_error(char *s);
void	read_file(char *argv);
void	extract_resolution(char *line, char *position);
char	*extract_texture(char *line, char *position);
void	extract_color(char *line, char *position);
int		check_len(char **aux, int num);
void    read_map(int fd);


#endif
