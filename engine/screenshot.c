/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:34:47 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 04:01:03 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dib_header2(int fd)
{
	unsigned int	image_size_byte;
	unsigned int	x_resolution_ppm;
	unsigned int	y_resolution_ppm;
	unsigned int	num_colors;
	unsigned int	important_colors;

	image_size_byte = 0;
	x_resolution_ppm = 0;
	y_resolution_ppm = 0;
	num_colors = 0;
	important_colors = 0;
	write(fd, &image_size_byte, sizeof(image_size_byte));
	write(fd, &x_resolution_ppm, sizeof(x_resolution_ppm));
	write(fd, &y_resolution_ppm, sizeof(y_resolution_ppm));
	write(fd, &num_colors, sizeof(num_colors));
	write(fd, &important_colors, sizeof(important_colors));
}

void	dib_header(int fd)
{
	unsigned int	width_px;
	unsigned int	height_px;
	short int		num_planes;
	short int		bit_per_pixel;
	unsigned int	compression;

	width_px = g_check.res_w;
	height_px = g_check.res_h;
	num_planes = 1;
	bit_per_pixel = 32;
	compression = 0;
	write(fd, &width_px, sizeof(width_px));
	write(fd, &height_px, sizeof(height_px));
	write(fd, &num_planes, sizeof(num_planes));
	write(fd, &bit_per_pixel, sizeof(bit_per_pixel));
	write(fd, &compression, sizeof(compression));
	dib_header2(fd);
}

void	bmp_header(int fd)
{
	unsigned char	type[2];
	int				file_size;
	int				reserved;
	int				offset;
	unsigned int	dib_header_size;

	type[0] = 'B';
	type[1] = 'M';
	file_size = (54) * g_check.res_w * g_check.res_h;
	reserved = 0;
	offset = 54;
	dib_header_size = 40;
	write(fd, &type, sizeof(type));
	write(fd, &file_size, sizeof(file_size));
	write(fd, &reserved, sizeof(reserved));
	write(fd, &offset, sizeof(offset));
	write(fd, &dib_header_size, sizeof(dib_header_size));
	dib_header(fd);
}

void	write_image(int fd, t_cub *cub)
{
	int	w;
	int	h;
	int	draw;

	h = 0;
	while (h++ < g_check.res_h)
	{
		w = 0;
		while (w++ < g_check.res_w)
		{
			draw = *(cub->mlx.data + (g_check.res_h - h)
					* g_check.res_w + w);
			write(fd, &draw, sizeof(draw));
		}
	}
}

void	screenshot(t_cub *cub)
{
	int		fd;

	fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC
			| O_APPEND);
	bmp_header(fd);
	write_image(fd, cub);
	close(fd);
	exit_game(cub);
}
