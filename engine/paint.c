/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 03:30:19 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/07 04:36:57 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    paint(t_raycast *ray, t_player *player, t_cub *cub)
{
	int		*tx;
	double	step;
	double	pos;
	int		y;

	y = ray->draw_start;
	step = 1.0 * g_check.res_h / ray->line_height;
	pos = (ray->draw_start - cub->texture.h / 2 + ray->line_height / 2) * step;
	tx = cub->texture.data;
	while (y < ray->draw_end)
	{
		cub->texture.colortx = tx[cub->texture.txt + (int)pos *
        cub->texture.sl / 4];
		if (ray->side == 1)
			cub->texture.colortx = cub->texture.colortx >> 1 & 8355711;
		cub->mlx.data[ray->x + y * cub->mlx.size_lenght / 4]
         = cub->texture.colortx;
		pos += step;
		y++;
	}
}