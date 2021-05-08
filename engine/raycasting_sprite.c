/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 05:04:14 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/08 03:53:51 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprite_order_distance(t_cub *cub, double *s_dist)
{
	int	tmp;
	int	dis_tmp;
	int	l;

	l = 0;
	while (l < g_check.n_sprites - 1)
	{
		if (s_dist[l] < s_dist[l + 1])
		{
			dis_tmp = s_dist[l];
			s_dist[l] = s_dist[l + 1];
			s_dist[l + 1] = dis_tmp;
			tmp = cub->s_cast.sprite_order[l];
			cub->s_cast.sprite_order[l] = cub->s_cast.sprite_order[l + 1];
			cub->s_cast.sprite_order[l + 1] = tmp;
			l = 0;
		}
		else
			l++;
	}
}

void	sprite_distance(t_cub *cub)
{
	int		l;
	double	sprite_distance[g_check.n_sprites];

	l = 0;
	while (l < g_check.n_sprites)
	{
		sprite_distance[l] = ((cub->player.pos_x - cub->sprite[l].x)
				* (cub->player.pos_x - cub->sprite[l].x)
						+ (cub->player.pos_y - cub->sprite[l].y)
							* (cub->player.pos_y - cub->sprite[l].y));
				cub->s_cast.sprite_order[l] = l;
		l++;
	}
	sprite_order_distance(cub, sprite_distance);
}

void		calculate_sprite(t_cub *cub, t_sprite_cas *scast)
{
	scast->h = abs((int)(g_check.res_h / (scast->transform_y)));
	scast->draw_start_y = -scast->h / 2 + g_check.res_h / 2;
	if (scast->draw_start_y < 0)
		scast->draw_start_y = 0;
	scast->draw_end_y = scast->h / 2 + g_check.res_h / 2;
	if (scast->draw_end_y >= g_check.res_h)
		scast->draw_end_y = g_check.res_h - 1;
	scast->w = abs((int)(g_check.res_h / (scast->transform_y)));
	scast->draw_start_x = -scast->w / 2 + scast->screen_x;
	if (scast->draw_start_x < 0)
		scast->draw_start_x = 0;
	scast->draw_end_x = scast->w / 2 + scast->screen_x;
	if (scast->draw_end_x >= g_check.res_w)
		scast->draw_end_x = g_check.res_w - 1;
}

void		paint_sprite(t_cub *cub, t_sprite_cas *scast)
{
	scast->stripe = scast->draw_start_x;
	while (scast->stripe++ < scast->draw_end_x)
	{
		scast->tex_x = (int)(256 * (scast->stripe - (-scast->w /
		2 + scast->screen_x)) * cub->texture.sp_w / scast->w) / 256;
		if (scast->transform_y > 0 && scast->stripe > 0 && scast->stripe <
			g_check.res_w && scast->transform_y <
			(float)cub->s_cast.z_buffer[scast->stripe])
		{
			scast->y = scast->draw_start_y;
			while (scast->y++ < scast->draw_end_y)
			{
				scast->d = (scast->y) * 256 -
				g_check.res_h * 128 + scast->h * 128;
				scast->tex_y = ((scast->d * cub->texture.sp_h)
				/ scast->h / 256);
				if (cub->texture.data_sp[scast->tex_x + scast->tex_y *
					cub->texture.sp_sl / 4])
					cub->mlx.data[(int)(scast->stripe + scast->y *
					cub->mlx.size_lenght / 4)] =
					cub->texture.data_sp[scast->tex_x + scast->tex_y *
					cub->texture.sp_sl / 4];
			}
		}
	}
}

void		raycasting_sprite(t_cub *cub)
{
	int				l;
	t_sprite_cas	scast;
	t_sprite		s;

	sprite_distance(cub);
	l = 0;
	while (l < g_check.n_sprites)
	{
		s = cub->sprite[cub->s_cast.sprite_order[l]];
		scast.x = ((s.x + 0.5) - cub->player.pos_x);
		scast.y = ((s.y + 0.5) - cub->player.pos_y);
		scast.inv_det = 1.0 / (cub->player.plane_x * cub->player.dir_y -
			cub->player.dir_x * cub->player.plane_y);
		scast.transform_x = scast.inv_det * (cub->player.dir_y *
			scast.x - cub->player.dir_x * scast.y);
		scast.transform_y = scast.inv_det * (-cub->player.plane_y *
			scast.x + cub->player.plane_x * scast.y);
		scast.screen_x = (int)((g_check.res_w / 2) *
			(1 + scast.transform_x / scast.transform_y));
		calculate_sprite(cub, &scast);
		paint_sprite(cub, &scast);
		l++;
	}
}
