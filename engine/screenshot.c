/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:34:47 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/27 16:16:56 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		dib_header2(int fd)
{
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;

	image_size = 0; // // NO SE USA AQUÍ
	ppm_x = 0; // pixeles por metro, // NO SE USA AQUÍ
	ppm_y = 0; // pixeles por metro, // NO SE USA AQUÍ
	clr_used = 0; // Número de colors // NO SE USA AQUÍ
	clr_important = 0; // Colores imprtantes // NO SE USA AQUÍ
	write(fd, &image_size, sizeof(image_size));
	write(fd, &ppm_x, sizeof(ppm_x));
	write(fd, &ppm_y, sizeof(ppm_y));
	write(fd, &clr_used, sizeof(clr_used));
	write(fd, &clr_important, sizeof(clr_important));
}

void		dib_header(int fd)
{

	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	width;
	unsigned int	height;

	planes = 1;
	bit_count = 32; // número de bits por píxel
	compression = 0; // No usar compresión // NO SE USA AQUÍ
	width = g_check.res_w; // resolución, es decir tamaño en píxeles del ancho
	height = g_check.res_h; // resolución, es decir tamaño en píxeles del alto
	write(fd, &width, sizeof(width));
	write(fd, &height, sizeof(height));
	write(fd, &planes, sizeof(planes));
	write(fd, &bit_count, sizeof(bit_count));
	write(fd, &compression, sizeof(compression));
	dib_header2(fd);
}

void		bmp_header(int fd)
{
	unsigned char	type[2];
	int				file_size;
	int				reserved;
	int				offset;
	unsigned int	size_header;

	type[0] = 'B'; // Valor fijo, identificativo de BMP
	type[1] = 'M'; // Valor fijo, identificativo de BMP
	file_size = (54) * g_check.res_w * g_check.res_h; //Tamaño de la imagen header, más la propia imagen
	reserved = 0;
	offset = 54; // A partín de que byte comienza el bitmap
	size_header = 40; // Qué tamaño tiene lo que falta de cabecera desde este punto
	write(fd, &type, sizeof(type));
	write(fd, &file_size, sizeof(file_size));
	write(fd, &reserved, sizeof(reserved));
	write(fd, &offset, sizeof(offset));
	write(fd, &size_header, sizeof(size_header));
	dib_header(fd);
}

void		write_image(int fd, t_cub *cub)
{
	int	l;
	int	j;
	int	draw;

	j = 0;
	while (j++ < g_check.res_h)
	{
		l = 0;
		while (l++ < g_check.res_w)
		{
			draw = *(cub->mlx.data + (g_check.res_h - j - 1) *
			g_check.res_w + l);
			write(fd, &draw, 4);
		}
	}
}

void		screenshot(t_cub *cub)
{
	int		fd;

	if (!(fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC |
		O_APPEND)))
		print_error("Is not possible to create cub3d.bmp");
	bmp_header(fd);
	write_image(fd, cub);
	close(fd);
	exit_game(cub);
}
