/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:28:38 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/27 18:18:56 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

/*
--check_arg()--
Comprobamos los argumentos pasados por consola para que se adapten a lo exigido
Lanzará un error en caso de que no sea así
En caso de tener "--save" como tercer argumento, salvamos una variable para usarlo posteriormente
*/

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
	t_engine *cub3d;
	
	check_arg(argc, argv);
	read_file(argv[1]);
	printf("El contador de parámetros es: %d\n", g_check.count_parameters);
	printf("La resolución es: %d x %d\n", g_check.resolution_width, g_check.resolution_hight);
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





	return(0);
}