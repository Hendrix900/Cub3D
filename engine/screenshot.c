/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:34:47 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/27 04:30:22 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_bmp	init_bmp(void)
{
	t_bmp	bmp;

	bmp.type[0] = 'B'; // Valor fijo, identificativo de BMP
	bmp.type[1] = 'M'; // Valor fijo, identificativo de BMP
	bmp.file_size = (54) * g_check.res_w * g_check.res_h; //Tamaño de la imagen header, más la propia imagen
	bmp.reserved = 0;
	bmp.offset = 54; // A partín de que byte comienza el bitmap
	bmp.size_header = 40; // Qué tamaño tiene lo que falta de cabecera desde este punto
	bmp.width = g_check.res_w; // resolución, es decir tamaño en píxeles del ancho
	bmp.height = g_check.res_h; // resolución, es decir tamaño en píxeles del alto
	bmp.planes = 1; // numero de planos, tiene que ser 1
	bmp.bit_count = 32; // número de bits por píxel
	bmp.compression = 0; // No usar compresión // NO SE USA AQUÍ
	bmp.image_size = 0; // // NO SE USA AQUÍ
	bmp.ppm_x = 0; // pixeles por metro, // NO SE USA AQUÍ
	bmp.ppm_y = 0; // pixeles por metro, // NO SE USA AQUÍ
	bmp.clr_used = 0; // Número de colors // NO SE USA AQUÍ
	bmp.clr_important = 0; // Colores imprtantes // NO SE USA AQUÍ
	return (bmp);
}

static void		write_bmp(int fd, t_bmp bmp)
{
	write(fd, &bmp.type, sizeof(bmp.type));
	write(fd, &bmp.file_size, sizeof(bmp.file_size));
	write(fd, &bmp.reserved, 4);
	write(fd, &bmp.offset, sizeof(bmp.offset));
	write(fd, &bmp.size_header, sizeof(bmp.size_header));
	write(fd, &bmp.width, sizeof(bmp.width));
	write(fd, &bmp.height, sizeof(bmp.height));
	write(fd, &bmp.planes, sizeof(bmp.planes));
	write(fd, &bmp.bit_count, sizeof(bmp.bit_count));
	write(fd, &bmp.compression, sizeof(bmp.compression));
	write(fd, &bmp.file_size, sizeof(bmp.file_size));
	write(fd, &bmp.ppm_x, sizeof(bmp.ppm_x));
	write(fd, &bmp.ppm_y, sizeof(bmp.ppm_y));
	write(fd, &bmp.clr_used, sizeof(bmp.clr_used));
	write(fd, &bmp.clr_important, sizeof(bmp.clr_important));
}

void    write_image(int fd, t_cub *cub)
{
	int	l;
	int	j;
	int	draw;

    j = 0;
	while (j++ < g_check.res_h)
	{
		l = 0;
		while (l++ <  g_check.res_w)
		{
			draw = *(cub->mlx.data + (g_check.res_h - j - 1) *
			g_check.res_w + l);
			write(fd, &draw, 4);
		}
    }
}

void        screenshot(t_cub *cub)
{
    int     fd;
   	t_bmp	bmp;

    if (!(fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC | 
        O_APPEND)))
        print_error("Is not possible to create cub3d.bmp");
    bmp = init_bmp();
	write_bmp(fd, bmp);
    write_image(fd, cub);
    close(fd);
    exit_game(cub);   
}
