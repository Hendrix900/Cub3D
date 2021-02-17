/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:28:38 by ccastill          #+#    #+#             */
/*   Updated: 2021/02/17 20:38:20 by ccastill         ###   ########.fr       */
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
	return(0);
}