/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 06:18:44 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/28 01:25:02 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H
# define A		97
# define W		119
# define S		115
# define D		100
# define LEFT	65361
# define RIGHT	65363
# define ESC	65307
# define ESC	65307
# define SPEED 	0.08
# define X_EXIT	33

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

typedef struct		s_check
{
	int				img_save;
	int				res_w;
	int				res_h;

	int				count_parameters;
	int				param_r;
	int				param_no;
	int				param_so;
	int				param_we;
	int				param_ea;
	int				param_s;
	int				param_f;
	int				param_c;

	char			*texture_no;
	char			*texture_so;
	char			*texture_we;
	char			*texture_ea;
	char			*texture_s;

	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				rgb_f;
	int				celing_r;
	int				celing_g;
	int				celing_b;
	int				rgb_c;

	int				n_columns;
	int				n_rows;
	char			**map;
	char			*buffer;

	char			player_ori;
	int				player_x;
	int				player_y;
	int				n_player;

	int				n_sprites;

}					t_check;
t_check				g_check;

typedef struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*image;
	int				*data;
	int				bpp;
	int				size_lenght;
	int				endian;
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

	void			*p_sp;
	int				*data_sp;
	int				sp_bpp;
	int				sp_sl;
	int				sp_end;
	int				sp_h;
	int				sp_w;

	int				txt;
	double			step;
	double			pos;
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

typedef struct		s_keys
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				rot_l;
	int				rot_r;
	int				esc;
}					t_keys;

typedef struct		s_player

{
	char			dir_player;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			speed;
}					t_player;

typedef struct		s_sprite
{
	double			x;
	double			y;
}					t_sprite;

typedef struct		s_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			wall_dist;
	double			wall_x;
	int				step_x;
	int				step_y;
	int				x;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_raycast;

typedef struct		s_sprite_casting
{
	double			x;
	double			y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				h;
	int				draw_start_y;
	int				draw_end_y;
	int				w;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				tex_x;
	int				s_y;
	int				d;
	int				tex_y;
	double			z_buffer[4000];
	int				*sprite_order;
	double			*sprite_distance;
}					t_sprite_cas;

typedef struct		s_cub
{
	t_mlx			mlx;
	t_text_wall		texture;
	t_player		player;
	t_keys			k;
	t_sprite		*sprite;
	t_sprite_cas	s_cast;
	t_raycast		ray;
}					t_cub;

void				print_error(char *s);
void				read_file(char *argv);
void				extract_resolution(char *line, char *position);
char				*extract_texture(char *line, char *position);
void				extract_color_celing(char *line, char *position);
void				extract_color_floor(char *line, char *position);
int					count_split(char **aux, int rows);
void				read_map(int fd, char *line);
void				read_moremap();
int					get_textures(t_cub *cub);
void				init_player(t_cub *cub);
int					raycasting(t_cub *cub);
void				set_texture(t_raycast *ray, t_player *player, t_cub *cub);
void				paint(t_cub *cub, t_raycast *ray, int x);
int					init_keys(t_cub *cub);
int					key_press(int k, t_cub *cub);
int					key_release(int k, t_cub *cub);
void				movement(t_cub *cub, t_player *player);
int					exit_game(t_cub *cub3d);
int					rgb_conver(int t, int r, int g, int b);
void				free_str(char **str);
int					check_path(char *position, char *line);
int					def_sprites(int n_sprites, t_cub *cub);
void				init_sprites (t_cub *cub);
void				raycasting_sprite(t_cub *cub);
void				screenshot(t_cub *cub);

#endif
