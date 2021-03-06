/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 03:39:52 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/06 05:08:29 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	raycasting(t_cub *cub)
{
	t_raycast	ray;
	int			x;

	x = 0;
	while (x < g_check.res_w)// Mientras x no sea igual al ancho de la resolución de la pantalla
	{
		ray.camera_x = 2 * x / (double)g_check.res_w - 1; //EL plano de cámara representa la superficie de la pantalla del pc. Nos servirá para calcular la proyección. Son las cordenadas X de dicho plano
		ray.ray_dir_x = cub->player.dir_x + cub->player.plane_x * ray.camera_x;
		ray.ray_dir_y = cub->player.dir_y + cub->player.plane_y * ray.camera_x;
		ray.map_x = (int)cub->player.pos_x;
		ray.map_y = (int)cub->player.pos_y;
		ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
		ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
		ray.hit = 0;
	}
	return (0);
}
