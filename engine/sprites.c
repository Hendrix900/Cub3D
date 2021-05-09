/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:01:36 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/09 20:23:35 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	def_sprites(int n_sprites, t_cub *cub)
{
	int	i;
	int	l;
	int	sprite_number;

	i = 0;
	sprite_number = 0;
	cub->sprite = malloc(sizeof(t_sprite) * n_sprites);
	cub->s_cast.sprite_order = (int *)malloc(sizeof(int) * cub->cf.n_sprites);
	while (cub->cf.map[i])
	{
		l = 0;
		while (l < cub->cf.n_columns)
		{
			if (cub->cf.map[i][l] == '4')
			{
				cub->sprite[sprite_number].x = i;
				cub->sprite[sprite_number].y = l;
				sprite_number++;
			}
			l++;
		}
		i++;
	}
	return (0);
}

void	get_num_sprites(t_cub *cub)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (i < cub->cf.n_rows)
	{
		j = 0;
		while (j < cub->cf.n_columns)
		{
			if (cub->cf.map[i][j] == '4')
			{
				cub->cf.n_sprites++;
			}
			j++;
		}
		i++;
	}
}

void	init_sprites(t_cub *cub)
{
	cub->cf.n_sprites = 0;
	get_num_sprites(cub);
	def_sprites(cub->cf.n_sprites, cub);
}
