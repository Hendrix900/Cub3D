/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 06:18:44 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/07 05:13:09 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# define X_EXIT 17

# include <X11/Xlib.h>
# include "./lib/mlx/minilibx-linux/mlx.h"
# include "./lib/libft/libft.h"
# include "./lib/get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>


typedef struct		s_check // Estructura de chequeo de variables
{
	int				img_save;
	int				res_w;
	int				res_h;

	///Contador de parámetros///
	int				count_parameters;
	int				param_r;
	int				param_no;
	int				param_so;
	int				param_we;
	int				param_ea;
	int				param_s;
	int				param_f;
	int				param_c;

	///Texturas///
	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	char			*texture_s;

	///Colors///
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				celing_r;
	int				celing_g;
	int				celing_b;

	///Mapa///
	int				n_columns;
	int				n_rows;
	char			**map;
	char			*buffer;

	///Player///
	char			player_ori; // Orientación del jugador
	int				player_x;
	int				player_y;
	int				n_player;

}					t_check;
t_check				g_check; // Declaración de la estructura

//Estructura del motor gráfico
typedef struct		s_mlx
{
	void			*ptr; // puntero de la inicialización de mlx_init
	void			*win; // puntero de la inicialización de mlx_new_window
	void			*image; // puntero de la inicialización de mlx_new_image
	int				*data; // Dirección de memoria donde se alberga la pantalla
	int				bpp; // Bits per pixel que guarda de la imagen abierta
	int				size_lenght; // Tamaño de bits
	int				endian; // tipo de arquitectura del SO, varía entre 1 y 0, si se le de iz a drch, o viceversa
}					t_mlx;

// Estructura de las texturas
typedef struct		s_text_wall
{
	void			*p_no; // puntero donde desde donde se carga la imagen
	int				*data_no; // IMPORTANTE
	int				no_bpp;
	int				no_sl;
	int				no_end;
	int				no_h;
	int				no_w;
	void			*p_we;
	int				*data_we;
	int				we_bpp;
	int				we_sl;
	int				we_end;
	int				we_h;
	int				we_w;
	void			*p_so;
	int				*data_so;
	int				so_bpp;
	int				so_sl;
	int				so_end;
	int				so_h;
	int				so_w;
	void			*p_ea;
	int				*data_ea;
	int				ea_bpp;
	int				ea_sl;
	int				ea_end;
	int				ea_h;
	int				ea_w;
	
	int				txt;
	int				*data;
	int				bpp;
	int				sl;
	int				end;
	int				h;
	int				w;
	int				colorc;
	int				colorf;
	int				colortx;
	char			wall_dir;
}					t_text_wall;

//Estructuras de los sprites
typedef struct		s_sprite
{
	void			*p_sp;
	int				*data_sp;
	int				sp_bpp;
	int				sp_sl;
	int				sp_end;
	int				sp_h;
	int				sp_w;
}					t_sprite;

// Estructura de las teclas
typedef struct		s_keys
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			rot_l;
	int			rot_r;
	int			esc;
}					t_keys;

// Estructura del player
typedef struct	s_player
{
	char		dir_player;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
	t_keys		key;
}				t_player;

// Estructura del raycasting
typedef struct	s_raycast
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_dist;
	double		wall_x; // Variable papra las texturas
	int			step_x;
	int			step_y;
	int			x;
	int			map_x;
	int			map_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		z_buffer[4000];
}				t_raycast;


// Estructura pincipal del motor
typedef struct		s_cub
{
	t_mlx			mlx;
	t_text_wall		texture;
	t_sprite		sprite;
	t_player		player;

}					t_cub;

void	print_error(char *s);
void	read_file(char *argv);
void	extract_resolution(char *line, char *position);
char	*extract_texture(char *line, char *position);
void	extract_color_celing(char *line, char *position);
void	extract_color_floor(char *line, char *position);
int		count_split(char **aux, int rows);
void	read_map(int fd, char *line);
void	read_moremap();
int		get_textures(t_cub *cub);
void    init_player(t_cub *cub);
int		raycasting(t_cub *cub);
void     set_texture(t_raycast *ray, t_player *player, t_cub *cub);
void    paint(t_raycast *ray, t_player *player, t_cub *cub);


#endif
