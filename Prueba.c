/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 10:15:37 by ccastill          #+#    #+#             */
/*   Updated: 2020/09/29 10:54:21 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct  s_data 
{
    void        *img;
    char        *addr;
    int        *addr_texture;
    void        *texture;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    void        *param;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             main(void)
{
    void    *mlx;
    void    *mlx_win;
    void    *xmp;
    int     x;
    int     y;
    t_data  img;
    char    *relative_path = "./textures/alien_egg.xpm";
    char    *relative_path1 = "./textures/nicolas-cage.xpm";

    int     img_width;
    int     img_height;

    x = 200;
    y = 200;
   
 
    mlx = mlx_init(); // Creamos la instancia para mlx
    mlx_win = mlx_new_window(mlx, 800, 600, "Cub3d"); //Creamos la ventana
    img.img = mlx_new_image(mlx, 800, 600); //Creamos una imagen donde pintar
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian); //Seleccionamos memoria
        
    while (y != 400)
    {
        while (x != 400)
        {
            my_mlx_pixel_put(&img, x, y, 0x0FF0000);
            x++;
        }
    x = 200;
    y++;
    }
    
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0); // Ponemos lo pintado/textura/sprite en la imagen
    img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height); // Abrimos una textura/sprite XMP
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 200); // Ponemos lo pintado/textura/sprite en la imagen
    
    img.img = mlx_xpm_file_to_image(mlx, relative_path1, &img_width, &img_height); // Abrimos una textura/sprite XMP
    mlx_put_image_to_window(mlx, mlx_win, img.img, 200, 400); // Ponemos lo pintado/textura/sprite en la imagen
    
    mlx_loop(mlx); // Loop para que no se cierre la ventana.
}
