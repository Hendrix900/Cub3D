/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 23:34:47 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/27 02:00:28 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    bit_shift(unsigned char *header, int file_size)
{
    header[0] = (unsigned char)(file_size);
    header[1] = (unsigned char)(file_size >> 8);
    header[2] = (unsigned char)(file_size >> 16);
    header[3] = (unsigned char)(file_size >> 24);    
}

void    write_header(int fd, t_cub *cub)
{
    unsigned char    header[54];
    int     file_size;
    
    file_size = 54 + (g_check.res_h * g_check.res_w * 4);
    ft_bzero(header, 54);
    header[0] = 0x42;
    header[1] = 0x4D;
    bit_shift(header + 2, file_size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
    bit_shift(header + 18, g_check.res_w);
    bit_shift(header + 22, g_check.res_h);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
    write(fd, header, 54);
}

void    write_image(int fd, t_cub *cub)
{
	int	x;
	int	y;
	int	draw;

    y = 0;
	while (y < g_check.res_h)
	{
		x = 0;
		while (x <  g_check.res_w)
		{
			draw = *(cub->mlx.data + (g_check.res_h - y - 1) *
			g_check.res_w + x);
			write(fd, &draw, 4);
			x++;
		}
		y++;
    }
}

void        screenshot(t_cub *cub)
{
    int     fd;

    if (!(fd = open("cub3d.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC | 
        O_APPEND)))
        print_error("Is not possible to create cub3d.bmp");
    write_header(fd, cub);
    write_image(fd, cub);
    close(fd);
    exit_game(cub);   
}
