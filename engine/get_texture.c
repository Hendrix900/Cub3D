/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 04:32:56 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/05 06:12:08 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_sprite(t_cub *cub)
{
	if (!(cub->sprite.p_sp = mlx_xpm_file_to_image(cub->mlx.ptr,
	g_check.texture_s, &cub->sprite.sp_w, &cub->sprite.sp_h)))
		print_error("Is not possible to open the sprite texture");
	cub->sprite.data_sp = (int *)mlx_get_data_addr(cub->sprite.p_sp,
		&cub->sprite.sp_bpp, &cub->sprite.sp_sl, &cub->sprite.sp_end);
	return (0);
}

int	get_textures(t_cub *cub)
{
	if (!(cub->texture.p_no = mlx_xpm_file_to_image(cub->mlx.ptr,
	g_check.texture_no, &cub->texture.no_w, &cub->texture.no_h)))
		print_error("Is not possible to open the NO texture");
	cub->texture.data_no = (int *)mlx_get_data_addr(cub->texture.p_no,
		&cub->texture.no_bpp, &cub->texture.no_sl, &cub->texture.no_end);
	if (!(cub->texture.p_we = mlx_xpm_file_to_image(cub->mlx.ptr,
		g_check.texture_we, &cub->texture.we_w, &cub->texture.we_h)))
		print_error("Is not possible to open the WE texture");
	cub->texture.data_we = (int *)mlx_get_data_addr(cub->texture.p_we,
	&cub->texture.we_bpp, &cub->texture.we_sl, &cub->texture.we_end);
	if (!(cub->texture.p_so = mlx_xpm_file_to_image(cub->mlx.ptr,
		g_check.texture_so, &cub->texture.so_w, &cub->texture.so_h)))
		print_error("Is not possible to open the WE texture");
	cub->texture.data_so = (int *)mlx_get_data_addr(cub->texture.p_so,
	&cub->texture.so_bpp, &cub->texture.so_sl, &cub->texture.so_end);
	if (!(cub->texture.p_ea = mlx_xpm_file_to_image(cub->mlx.ptr,
		g_check.texture_ea, &cub->texture.ea_w, &cub->texture.ea_h)))
		print_error("Is not possible to open the WE texture");
	cub->texture.data_ea = (int *)mlx_get_data_addr(cub->texture.p_ea,
	&cub->texture.ea_bpp, &cub->texture.ea_sl, &cub->texture.ea_end);
	get_sprite(cub);
	return (0);
}
