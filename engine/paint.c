/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:07:42 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/09 04:56:51 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	paint(t_cub *cub, t_raycast *ray, int x)
{
	int i;

	i = 0;
	while (i < ray->draw_start)
	{
		*(cub->mlx.data + (i * g_check.res_w) + x) = g_check.rgb_c;
		i++;
	}
	while (i < ray->draw_end)
	{
		cub->texture.y = (int)cub->texture.pos & (cub->texture.h - 1);
		cub->texture.pos += cub->texture.step;
		cub->texture.colortx = cub->texture.data[cub->texture.txt +
		(int)cub->texture.pos * cub->texture.sl / 4];
		if (ray->ray_dir_x < 0 && ray->side == 0)
			cub->texture.colortx = cub->texture.colortx >> 1 & 8355711;
		*(cub->mlx.data + (i * g_check.res_w) + x) = cub->texture.colortx;
		i++;
	}
	while (i < g_check.res_h - 1)
	{
		*(cub->mlx.data + (i * g_check.res_w) + x) =g_check.rgb_f;
		i++;
	}
}
