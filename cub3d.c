/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:28:38 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/06 03:39:31 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

int	open_window(t_cub *cub)
{
	if (!(cub->mlx.ptr = mlx_init()))
		print_error("Is not possible to initialize the mlx_init");
	if (!(cub->mlx.win = mlx_new_window(cub->mlx.ptr, g_check.res_w, 
	g_check.res_h, "Cub3d")))
		print_error("The window creation fail");
	if (!(cub->mlx.image = mlx_new_image(cub->mlx.ptr, g_check.res_w, 
	g_check.res_h)))
		print_error("Is not possible to create a new image");
	cub->mlx.data = (int *)mlx_get_data_addr(cub->mlx.image, &cub->mlx.bpp, 
	&cub->mlx.size_lenght, &cub->mlx.endian);
	get_textures(cub);
	init_player(cub);
		
	printf("el contenido de cub->mlx.bpp es %d\n", cub->mlx.bpp);
	printf("el contenido de cub->mlx.size_line, es %d\n", cub->mlx.size_lenght);
	printf("el contenido de cub->mlx.endian, es %d\n", cub->mlx.endian);
	printf("el contenido de mlx.data es %d\n", cub->mlx.data[0]);

	printf("el contenido de cub->texture.no_w es %d\n", cub->texture.no_w);
	printf("el contenido de cub->texture.no_h es %d\n", cub->texture.no_h);

	printf("el contenido de cub->texture.no_bpp es %d\n", cub->texture.no_bpp);
	printf("el contenido de cub->texture.no_sl, es %d\n", cub->texture.no_sl);
	printf("el contenido de cub->texture.no_end, es %d\n", cub->texture.no_end);
	printf("el contenido de cub->texture.data_no[0] es %d\n", cub->texture.data_no[1]);
	
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win , cub->texture.p_no, 0, 0);


	mlx_loop(cub->mlx.ptr);
}

void	check_arg(int argc, char **argv)
{
	g_check.img_save = 0;
	if (argc <= 1 || argc > 3)
		print_error("The number of arguments are incorrect");
	if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))))
		print_error("The argument must have the extension .cub");
	if (argc == 3)
	{
		if ((ft_strlen(argv[2]) != 6) || 
			(!(ft_strnstr(argv[2], "--save", ft_strlen(argv[2])))))
			print_error("The third argument has to be --save");
		else
			g_check.img_save = 1;		
	}
}

int	main(int argc, char **argv)
{
	t_cub cub;
		
	check_arg(argc, argv);
	read_file(argv[1]);
	open_window(&cub);
	raycasting(&cub);
		
	printf("El contador de parámetros es: %d\n", g_check.count_parameters);
	printf("La resolución es: %d x %d\n", g_check.res_w, g_check.res_h);
	printf("La ruta de la textura NO es: %s\n", g_check.texture_no);
	printf("La ruta de la textura SO es: %s\n", g_check.texture_so);
	printf("La ruta de la textura WE es: %s\n", g_check.texture_we);
	printf("La ruta de la textura EA es: %s\n", g_check.texture_ea);
	printf("La ruta de la textura S es: %s\n", g_check.texture_s);
	printf("El color del suelo (R) es: %d\n", g_check.floor_r);
	printf("El color del suelo (G) es: %d\n", g_check.floor_g);
	printf("El color del suelo (B) es: %d\n", g_check.floor_b);
	printf("El color del techo (R) es: %d\n", g_check.celing_r);
	printf("El color del techo (G) es: %d\n", g_check.celing_g);
	printf("El color del techo (B) es: %d\n", g_check.celing_b);
	printf("El número de columnas es: %d\n", g_check.n_columns);
	printf("El número de filas es: %d\n", g_check.n_rows);
	printf("La posición x del jugador es: %d\n", g_check.player_x);
	printf("La posición y del jugador es: %d\n", g_check.player_y);
	printf("La direcciond el jugador es %c\n", g_check.player_ori);
	int l = 0;
	while (g_check.map[l])
	{
		printf("El contenido del map[%d]  es: %s\n",l, g_check.map[l]);
		l++;
	}
	return(0);
}
