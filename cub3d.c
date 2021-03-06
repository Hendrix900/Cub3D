/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 23:28:38 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:14:38 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d.h"

static void	destroy_create_image(t_cub *cub)
{
	mlx_destroy_image(cub->mlx.ptr, cub->mlx.image);
	cub->mlx.image = mlx_new_image(cub->mlx.ptr, cub->cf.res_w,
			cub->cf.res_h);
	cub->mlx.data = (int *)mlx_get_data_addr(cub->mlx.image, &cub->mlx.bpp,
			&cub->mlx.size_lenght, &cub->mlx.endian);
}

int	run_game(t_cub *cub)
{
	movement(cub, &cub->player);
	raycasting(cub);
	raycasting_sprite(cub);
	mlx_put_image_to_window(cub->mlx.ptr, cub->mlx.win, cub->mlx.image, 0, 0);
	if (cub->cf.img_save == 1)
		screenshot(cub);
	destroy_create_image(cub);
}

int	open_window(t_cub *cub)
{
	int	max_x;
	int	max_y;

	cub->mlx.ptr = mlx_init();
	mlx_get_screen_size(cub->mlx.ptr, &max_x, &max_y);
	if (max_x < cub->cf.res_w)
		cub->cf.res_w = max_x;
	if (max_y < cub->cf.res_h)
		cub->cf.res_h = max_y;
	cub->mlx.win = mlx_new_window(cub->mlx.ptr, cub->cf.res_w,
			cub->cf.res_h, "cub3D");
	cub->mlx.image = mlx_new_image(cub->mlx.ptr, cub->cf.res_w,
			cub->cf.res_h);
	cub->mlx.data = (int *)mlx_get_data_addr(cub->mlx.image, &cub->mlx.bpp,
			&cub->mlx.size_lenght, &cub->mlx.endian);
}

void	check_arg(int argc, char **argv, t_cub *cub)
{
	cub->cf.img_save = 0;
	if (argc <= 1 || argc > 3)
		print_error_arg("The number of arguments are incorrect");
	if (!(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))))
		print_error_arg("The argument must have the extension .cub");
	if (argc == 3)
	{
		if ((ft_strlen(argv[2]) != 6) || (!(ft_strnstr(argv[2], "--save",
						ft_strlen(argv[2])))))
			print_error_arg("The third argument has to be --save");
		else
			cub->cf.img_save = 1;
	}
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	check_arg(argc, argv, &cub);
	read_file(argv[1], &cub);
	open_window(&cub);
	get_textures(&cub);
	init_player(&cub);
	init_keys(&cub);
	init_sprites(&cub);
	mlx_hook(cub.mlx.win, X_EXIT, 1L << 17, exit_game, &cub);
	mlx_hook(cub.mlx.win, 2, 1, key_press, &cub);
	mlx_key_hook(cub.mlx.win, key_release, &cub);
	mlx_loop_hook(cub.mlx.ptr, run_game, &cub);
	mlx_loop(cub.mlx.ptr);
	return (0);
}
