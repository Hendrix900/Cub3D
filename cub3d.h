/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 06:18:44 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/27 00:38:17 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
#  define A 97
#  define W 119
#  define S 115
#  define D 100
#  define LEFT 65361
#  define RIGHT 65363
#  define ESC 65307
#  define ESC 65307
#  define SPEED 0.08
# define X_EXIT 33

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

typedef struct		s_check 			// Estructura de que almacena los valores extraidos del archivo
{
	//--Variables de la pantalla--//
	int				img_save;			// Variable que nos informa si se quiere hacer un --save
	int				res_w;				// Resolución ancho
	int				res_h;				// Resolución largo
	
	//--Contador de parámetros--//
	int				count_parameters; 	// Contador de parámetros generales
	int				param_r;			// Resolución
	int				param_no;			// North
	int				param_so;			// South
	int				param_we;			// Weast
	int				param_ea;			// East
	int				param_s;			// Sprite
	int				param_f;			// Floor
	int				param_c;			// Celing

	//--Texturas--//
	char			*texture_no;		// Almacenamiento de la RUTA textura North
	char			*texture_so;		// Almacenamiento de la RUTA textura South
	char			*texture_we;		// Almacenamiento de la RUTA textura Weast
	char			*texture_ea;		// Almacenamiento de la RUTA textura East
	char			*texture_s;			// Almacenamiento de la RUTA textura Sprite

	//--Colores-//
	int				floor_r;			// Almacenamos el color RED del Floor
	int				floor_g;			// Almacenamos el color Green del Floor
	int				floor_b;			// Almacenamos el color Blue del Floor
	int				rgb_f;
	int				celing_r;			// Almacenamos el color RED del Celing
	int				celing_g;			// Almacenamos el color RED del Celing
	int				celing_b;			// Almacenamos el color RED del Celing
	int				rgb_c;				// Color convertido por rgb_convert

	//--Mapa--//
	int				n_columns;			// Número de Columns del mapa
	int				n_rows;				// Numero de Rows del mapa
	char			**map;				// Array bidimensiona que contiene el mapa
	char			*buffer;			// Contendrá el line + \n

	//--Player--//
	char			player_ori; 		// Orientación del jugador
	int				player_x;			// Posición X del jugador
	int				player_y;			// Posición Y del jugador
	int				n_player;			// Número de jugadores
	
	//--Sprites--//
	int				n_sprites;			// numero de sprites en el mapa

}					t_check;
t_check				g_check; 			


typedef struct		s_mlx				// Estructura principal de la ventana
{
	void			*ptr; 				// Puntero de la inicialización de mlx_init
	void			*win; 				// Puntero de la inicialización de mlx_new_window
	void			*image; 			// Puntero de la inicialización de mlx_new_image
	int				*data; 				// Dirección de memoria donde se alberga la pantalla
	int				bpp; 				// Bits per pixel que guarda de la imagen abierta
	int				size_lenght; 		// Tamaño de bits
	int				endian; 			// Tipo de arquitectura del SO, varía entre 1 y 0, si se lee de iz a drch, o viceversa
}					t_mlx;

typedef struct		s_text_wall			// Estructura de almacenamiento de las texturas
{
	void			*p_no; 				// Puntero donde desde donde se carga la imagen
	int				*data_no;			// IMPORTANTE
	int				no_bpp;				//
	int				no_sl;				//
	int				no_end;				//
	int				no_h;				// Alto de la textura North
	int				no_w;				// Ancho de la textura North
	
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

	//--Sprite--//
	void			*p_sp;
	int				*data_sp;
	int				sp_bpp;
	int				sp_sl;
	int				sp_end;
	int				sp_h;
	int				sp_w;
	

	//--TEXTURAS EN MUROS--//
	int				txt;
	double			step; // Añadido recientemente
	double			pos; // Añadido recientemente
	int				y;
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

typedef struct		s_keys			// Estructura de las teclas
{
	int			up;
	int			down;
	int			left;
	int			right;
	int			rot_l;
	int			rot_r;
	int			esc;
}					t_keys;

typedef struct	s_player			// Estructura del player

{
	char		dir_player;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		speed;
}				t_player;

typedef struct		s_sprite
{
	double			x;
	double			y;
	int				num;			// Necesario?
}					t_sprite;

typedef struct	s_raycast			// Estructura del raycasting
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		wall_dist;
	double		wall_x; 			// Variable para las texturas
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
}				t_raycast;

typedef struct 	s_sprite_casting	//Estructura para el raycasting de los sprites
{
	double		x;
	double		y;
	double		inv_det;
	double		transform_x;
	double		transform_y;
	int			screen_x;
	int			h;
	int			draw_start_y;
	int			draw_end_y;
	int			w;
	int			draw_start_x;
	int			draw_end_x;
	int			stripe;
	int			tex_x;
	int			s_y;
	int			d;
	int			tex_y;
	//Mudanza de varioables desde raycasting
	double		z_buffer[4000];			// Z buffer, sprites!
	int			*sprite_order;
	double		*sprite_distance;
}				t_sprite_cas;	

typedef struct		s_cub			// Estructura padre
{
	t_mlx			mlx;
	t_text_wall		texture;
	t_player		player;
	t_keys			k;
	t_sprite		*sprite;
	t_sprite_cas	s_cast;			// Añadido recientemente para los sprite.
	t_raycast		ray;			// NO SE SI SE USARÁ
}					t_cub;

void			print_error(char *s);
void			read_file(char *argv);
void			extract_resolution(char *line, char *position);
char			*extract_texture(char *line, char *position);
void			extract_color_celing(char *line, char *position);
void			extract_color_floor(char *line, char *position);
int				count_split(char **aux, int rows);
void			read_map(int fd, char *line);
void			read_moremap();
int				get_textures(t_cub *cub);
void			init_player(t_cub *cub);
int				raycasting(t_cub *cub);
void			set_texture(t_raycast *ray, t_player *player, t_cub *cub);
void			paint(t_cub *cub, t_raycast *ray, int x);
int				init_keys(t_cub *cub);
int				key_press(int k, t_cub *cub);
int				key_release(int k, t_cub *cub);
void			movement(t_cub *cub, t_player *player);
int				exit_game(t_cub *cub3d);
int				rgb_conver(int t, int r, int g, int b);
void			free_str(char **str);
int				check_path(char *position, char *line);
int				def_sprites(int n_sprites, t_cub *cub);
void			init_sprites (t_cub *cub);
void			raycasting_sprite(t_cub *cub);
void			screenshot(t_cub *cub);

#endif
