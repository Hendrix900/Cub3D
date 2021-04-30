/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:01:36 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/30 01:55:46 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		def_sprites(int n_sprites, t_cub *cub)
{
	int		i;
	int		l;
	int		sprite_number;

	i = 0;
	sprite_number = 0;
	cub->sprite = malloc(sizeof(t_sprite) * n_sprites);
	cub->s_cast.sprite_order = (int *)malloc(sizeof(int) * g_check.n_sprites);
	while (g_check.map[i])
	{
		l = 0;
		while (l < g_check.n_columns)
		{
			if (g_check.map[i][l] == '4')
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

void				get_num_sprites(void)
{
	int i;
	int j;
	int num;

	i = 0;
	num = 0;
	while (i < g_check.n_rows)
	{
		j = 0;
		while (j < g_check.n_columns)
		{
			if (g_check.map[i][j] == '4')
			{
				g_check.n_sprites++;
			}
			j++;
		}
		i++;
	}
	printf("num base es %d\n", g_check.n_sprites);
}
	
void	init_sprites(t_cub *cub)
{
	get_num_sprites();
	def_sprites(g_check.n_sprites, cub);
}
