/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 01:30:42 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/09 19:53:37 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_textorientation2(t_cub *cub, t_raycast *ray)
{
	if (ray->ray_dir_y < 0 && ray->side == 1)
	{
		cub->texture.data = cub->texture.data_we;
		cub->texture.sl = cub->texture.we_sl;
		cub->texture.h = cub->texture.we_h;
		cub->texture.w = cub->texture.we_w;
	}
	if (ray->ray_dir_y > 0 && ray->side == 1)
	{
		cub->texture.data = cub->texture.data_ea;
		cub->texture.sl = cub->texture.ea_sl;
		cub->texture.h = cub->texture.ea_h;
		cub->texture.w = cub->texture.ea_w;
	}
}

void	set_textorientation1(t_cub *cub, t_raycast *ray)
{
	if (ray->ray_dir_x < 0 && ray->side == 0)
	{
		cub->texture.data = cub->texture.data_no;
		cub->texture.sl = cub->texture.no_sl;
		cub->texture.h = cub->texture.no_h;
		cub->texture.w = cub->texture.no_w;
	}
	if (ray->ray_dir_x > 0 && ray->side == 0)
	{
		cub->texture.data = cub->texture.data_so;
		cub->texture.sl = cub->texture.so_sl;
		cub->texture.h = cub->texture.so_h;
		cub->texture.w = cub->texture.so_w;
	}
	set_textorientation2(cub, ray);
}

void	set_texture(t_raycast *ray, t_player *player, t_cub *cub)
{
	set_textorientation1(cub, ray);
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player->pos_x + ray->wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	cub->texture.txt = (int)(ray->wall_x * (double)(cub->texture.w));
	if (ray->side == 0 && ray->ray_dir_x > 0)
		cub->texture.txt = cub->texture.w - cub->texture.txt - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		cub->texture.txt = cub->texture.w - cub->texture.txt - 1;
	cub->texture.step = 1.0 * cub->texture.h / ray->line_height;
	cub->texture.pos = (ray->draw_start - cub->cf.res_h / 2
			+ ray->line_height / 2) * cub->texture.step;
}
