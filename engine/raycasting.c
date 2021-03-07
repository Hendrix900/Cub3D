/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 03:39:52 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/07 04:37:30 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_height(t_raycast *ray)
{
	ray->line_height = (int)(g_check.res_h / ray->wall_dist);
	ray->draw_start = (ray->line_height * -1) / 2 + g_check.res_h / 2;
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + g_check.res_h / 2;
	if (ray->draw_end >= g_check.res_h || ray->draw_end <= 0)
		ray->draw_end = g_check.res_w - 1;
}

void	calculate_wall_distance(t_cub *cub, t_raycast *ray, t_player *player)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x < 0)
			cub->texture.wall_dir = 'N';
		else
			cub->texture.wall_dir = 'S';
		ray->wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) // Distancia al muro
		/ ray->ray_dir_x;
		ray->wall_x = player->pos_y + ray->wall_dist * ray->ray_dir_y; // Punto donde el rayo golpea con el muro, punto exácto
	}
	else
	{
		if (ray->ray_dir_y < 0)
			cub->texture.wall_dir = 'W';
		else
			cub->texture.wall_dir = 'E';
		ray->wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) 
		/ ray->ray_dir_y;
		ray->wall_x = player->pos_x + ray->wall_dist * ray->ray_dir_x; // Punto donde el rayo golpea con el muro, punto exácto
	}
}

void	dda_hit_wall(t_raycast *ray, t_player *player)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (g_check.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
}

void	init_step(t_raycast *ray, t_player *player)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) *
		ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->step_y) *
		ray->delta_dist_y;
	}
}

int		raycasting(t_cub *cub)
{
	t_raycast	ray;
	t_player	player;
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
		init_step(&ray, &player);
		dda_hit_wall(&ray, &player);
		calculate_wall_distance(cub, &ray, &player);
		calculate_height(&ray);
		set_texture(&ray, &player, cub); // Working progess
		ray.z_buffer[x] = ray.wall_dist;
		paint(&ray, &player, cub); // Working progess
		x++;
	}
	return (0);
}
