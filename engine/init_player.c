/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 19:01:24 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/10 22:16:02 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_direction2(t_cub *cub)
{
	if (cub->cf.player_ori == 'E')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = 1;
		cub->player.plane_x = 0.66;
		cub->player.plane_y = 0;
	}
	if (cub->cf.player_ori == 'W')
	{
		cub->player.dir_x = 0;
		cub->player.dir_y = -1;
		cub->player.plane_x = -0.66;
		cub->player.plane_y = 0;
	}
}

void	player_direction(t_cub *cub)
{
	if (cub->cf.player_ori == 'N')
	{
		cub->player.dir_x = -1;
		cub->player.dir_y = 0;
		cub->player.plane_x = 0;
		cub->player.plane_y = 0.66;
	}
	if (cub->cf.player_ori == 'S')
	{
		cub->player.dir_x = 1;
		cub->player.dir_y = 0;
		cub->player.plane_x = 0;
		cub->player.plane_y = -0.66;
	}
	player_direction2(cub);
}

void	init_player(t_cub *cub)
{
	cub->player.pos_x = (double)cub->cf.player_x + 0.5;
	cub->player.pos_y = (double)cub->cf.player_y + 0.5;
	player_direction(cub);
}
