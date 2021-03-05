/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 06:18:44 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/05 03:43:36 by ccastill         ###   ########.fr       */
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
	int			res_w;
	int			res_h;
	
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

	///Mapa///
	int			n_columns;
	int			n_rows;
	char		**map;
	char		*buffer;

	///Player///
	int			player_x;
	int			player_y;
	int			n_player;

}				t_check;
t_check			g_check; // Declaración de la estructura

//Estructura del motor gráfico
typedef struct	s_mlx
{
	void			*ptr; // puntero de la inicialización de mlx_init
	void			*win; // puntero de la inicialización de mlx_new_window
	void			*image; // puntero de la inicialización de mlx_new_image
	int				*data; // Dirección de memoria donde se alberga 
	int				bpp; // Bits per pixel que guarda de la imagen abierta
	int				size_lenght; // Tamaño de bits
	int				endian; // tipo de arquitectura del SO, varía entre 1 y 0, si se le de iz a drch, o viceversa
}					t_mlx;

typedef struct		s_text_wall
{
	void			*p_no;
	int				*data_no;
	int				no_bpp;
	int				no_sl;
	int				no_end;
	int				no_h;
	int				no_w;
	
}					t_text_wall;

typedef struct		s_cub
{	
	t_mlx			mlx;
	t_text_wall		texture;
}					t_cub;



void	print_error(char *s);
void	read_file(char *argv);
void	extract_resolution(char *line, char *position);
char	*extract_texture(char *line, char *position);
void	extract_color_celing(char *line, char *position);
void	extract_color_floor(char *line, char *position);
int		count_split(char **aux, int rows);
void    read_map(int fd, char *line);
void    read_moremap();



#endif
