/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 03:26:17 by ccastill          #+#    #+#             */
/*   Updated: 2021/03/08 07:26:11 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	init_keys(t_cub *cub)
{
	cub->k.up = 0;
	cub->k.down = 0;
	cub->k.left = 0;
	cub->k.right = 0;
	cub->k.rot_l = 0;
	cub->k.rot_r = 0;
	return (0);
}

int	key_press(int k, t_cub *cub)
{
	if (k == W)
		cub->k.up  = 1;
	else if (k == S)
		cub->k.down = 1;
	else if (k == A)
		cub->k.left = 1;
	else if (k == D)
		cub->k.right = 1;
	else if (k == LEFT)
		cub->k.rot_l  = 1;
	else if (k == RIGHT)
		cub->k.rot_r = 1;
	else if (k == ESC)
		exit_game(cub); 
	return (0);
}

int	key_release(int k, t_cub *cub)
{
	if (k == W)
		cub->k.up = 0;
	else if (k == S)
		cub->k.down = 0;
	else if (k == A)
		cub->k.left = 0;
	else if (k == D)
		cub->k.right = 0;
	else if (k == LEFT)
		cub->k.rot_l  = 0;
	else if (k == RIGHT)
		cub->k.rot_r = 0;
	return (0);
}
