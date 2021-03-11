/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 02:03:13 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/12 00:17:26 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		rotation(t_cub *cub, t_player *player)
{
	double old_dir_x;
	double old_plane_x;
	double s;

	s = 0.05;
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	if (cub->k.rot_r)
	{
		player->dir_x = player->dir_x * cos(-s) - player->dir_y * sin(-s);
		player->plane_x = player->plane_x * cos(-s) - player->plane_y * sin(-s);
		player->dir_y = old_dir_x * sin(-s) + player->dir_y * cos(-s);
		player->plane_y = old_plane_x * sin(-s) + player->plane_y * cos(-s);
	}
	if (cub->k.rot_l)
	{
		player->dir_x = player->dir_x * cos(s) - player->dir_y * sin(s);
		player->plane_x = player->plane_x * cos(s) - player->plane_y * sin(s);
		player->dir_y = old_dir_x * sin(s) + player->dir_y * cos(s);
		player->plane_y = old_plane_x * sin(s) + player->plane_y * cos(s);
	}
	return (0);
}

int		can_move(char pos)
{
	if (pos == '1' || pos == '4')
		return (0);
	return (1);
}

int		left_right(t_cub *cub, t_player *player)
{
	if (cub->k.left)
	{
		if (can_move(g_check.map[(int)player->pos_x]
		[(int)(player->pos_y + player->dir_x * SPEED)]))
			player->pos_y += player->dir_x * SPEED;
		if (can_move(g_check.map[(int)(player->pos_x - player->dir_y * SPEED)]
		[(int)player->pos_y]))
			player->pos_x -= player->dir_y * SPEED;
	}
	if (cub->k.right)
	{
		if (can_move(g_check.map[(int)player->pos_x]
		[(int)(player->pos_y - player->dir_x * SPEED)]))
			player->pos_y -= player->dir_x * SPEED;
		if (can_move(g_check.map[(int)(player->pos_x + player->dir_y * SPEED)]
		[(int)player->pos_y]))
			player->pos_x += player->dir_y * SPEED;
	}
	return (0);
}

int		move_fow_back(t_cub *cub, t_player *player)
{
	if (cub->k.up)
	{
		if (can_move(g_check.map[(int)(player->pos_x + player->dir_x * SPEED)]
		[(int)player->pos_y]))
			player->pos_x += player->dir_x * SPEED;
		if (can_move(g_check.map[(int)player->pos_x][(int)
		(player->pos_y + player->dir_y * SPEED)]))
			player->pos_y += player->dir_y * SPEED;
	}
	if (cub->k.down)
	{
		if (can_move(g_check.map[(int)(player->pos_x - player->dir_x * SPEED)]
		[(int)player->pos_y]))
			player->pos_x -= player->dir_x * SPEED;
		if (can_move(g_check.map[(int)player->pos_x]
		[(int)(player->pos_y - player->dir_y * SPEED)]))
			player->pos_y -= player->dir_y * SPEED;
	}
	return (0);
}

void	movement(t_cub *cub, t_player *player)
{
	move_fow_back(cub, player);
	left_right(cub, player);
	rotation(cub, player);
}
