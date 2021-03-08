/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:07:42 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/08 03:15:03 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    paint(t_cub *cub, t_raycast *ray, int x)
{

    int i;
    int *tx;

    i = 0;
    tx = cub->texture.data;
    while (i < ray->draw_start) 
	{
		*(cub->mlx.data + (i * g_check.res_w) + x) = 0x91443a;
		i++;
	}
    while (i < ray->draw_end)
	{
		cub->texture.pos += cub->texture.step;
		cub->texture.colortx = tx[cub->texture.txt + (int)cub->texture.pos * cub->texture.sl / 4];
        if (ray->side == 1)
			cub->texture.colortx = cub->texture.colortx >> 1 & 8355711;
		*(cub->mlx.data + (i * g_check.res_w) + x) = cub->texture.colortx;
		i++;
	}
    
    while (i < g_check.res_h - 1)
	{
		*(cub->mlx.data + (i * g_check.res_w) + x) = 0x919ea4;
		i++;
	}
}