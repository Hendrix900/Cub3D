/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 04:32:56 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:15:55 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_sprite(t_cub *cub)
{
	cub->texture.p_sp = mlx_xpm_file_to_image(cub->mlx.ptr, cub->cf.texture_s,
			&cub->texture.sp_w, &cub->texture.sp_h);
	if (!(cub->texture.p_sp))
		exit_game_texture("Is not possible to open the sprite texture", cub);
	cub->texture.data_sp = (int *)mlx_get_data_addr(cub->texture.p_sp,
			&cub->texture.sp_bpp, &cub->texture.sp_sl, &cub->texture.sp_end);
	return (0);
}

int	get_textures2(t_cub *cub)
{
	cub->texture.p_so = mlx_xpm_file_to_image(cub->mlx.ptr, cub->cf.texture_so,
			&cub->texture.so_w, &cub->texture.so_h);
	if (!(cub->texture.p_so))
		exit_game_texture("Is not possible to open the SO texture", cub);
	cub->texture.data_so = (int *)mlx_get_data_addr(cub->texture.p_so,
			&cub->texture.so_bpp, &cub->texture.so_sl, &cub->texture.so_end);
	cub->texture.p_ea = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->cf.texture_ea, &cub->texture.ea_w, &cub->texture.ea_h);
	if (!(cub->texture.p_ea))
		exit_game_texture("Is not possible to open the EA texture", cub);
	cub->texture.data_ea = (int *)mlx_get_data_addr(cub->texture.p_ea,
			&cub->texture.ea_bpp, &cub->texture.ea_sl, &cub->texture.ea_end);
}

int	get_textures(t_cub *cub)
{
	cub->texture.p_no = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->cf.texture_no, &cub->texture.no_w, &cub->texture.no_h);
	if (!(cub->texture.p_no))
		exit_game_texture("Is not possible to open the NO texture", cub);
	cub->texture.data_no = (int *)mlx_get_data_addr(cub->texture.p_no,
			&cub->texture.no_bpp, &cub->texture.no_sl, &cub->texture.no_end);
	cub->texture.p_we = mlx_xpm_file_to_image(cub->mlx.ptr,
			cub->cf.texture_we, &cub->texture.we_w, &cub->texture.we_h);
	if (!(cub->texture.p_we))
		exit_game_texture("Is not possible to open the WE texture", cub);
	cub->texture.data_we = (int *)mlx_get_data_addr(cub->texture.p_we,
			&cub->texture.we_bpp, &cub->texture.we_sl, &cub->texture.we_end);
	get_textures2(cub);
	get_sprite(cub);
	return (0);
}
