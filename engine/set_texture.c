/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:30:42 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/07 05:20:49 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void     set_texture2(t_raycast *ray, t_player *player, t_cub *cub)
{
  if (cub->texture.wall_dir == 'E')
	{
		cub->texture.data = cub->texture.data_ea;
		cub->texture.sl = cub->texture.ea_sl;
		cub->texture.h = cub->texture.ea_h;
		cub->texture.w = cub->texture.ea_w;
	}
	else if (cub->texture.wall_dir == 'W')
	{
		cub->texture.data= cub->texture.data_we;
		cub->texture.sl = cub->texture.we_sl;
		cub->texture.h = cub->texture.we_h;
	    cub->texture.w  = cub->texture.we_w;
	}   
}
void     set_texture(t_raycast *ray, t_player *player, t_cub *cub)
{
 	ray->wall_x -= floor((ray->wall_x));
    if (cub->texture.wall_dir == 'N')
	{
		cub->texture.data = cub->texture.data_no;
		cub->texture.sl = cub->texture.no_sl;
		cub->texture.h = cub->texture.no_h;
		cub->texture.w = cub->texture.no_w;
	}
	else if (cub->texture.wall_dir == 'S')
	{
		cub->texture.data= cub->texture.data_so;
		cub->texture.sl = cub->texture.so_sl;
		cub->texture.h = cub->texture.so_h;
	    cub->texture.w  = cub->texture.so_w;
	}
    set_texture2(ray, player, cub);
	///CAMBAIR LO DE DEBAJO
	cub->texture.txt = (int)(ray->wall_x * (double)cub->texture.w);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		cub->texture.txt = (cub->texture.w - cub->texture.txt  - 1);
	if (ray->side == 1 && ray->ray_dir_y < 0)
		cub->texture.txt = (cub->texture.w - cub->texture.txt - 1);
        
}