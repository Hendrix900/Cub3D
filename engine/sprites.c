/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 03:01:36 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/24 21:23:49 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int    def_sprites(int n_sprites)
{
    t_sprite    *sprites;
    int         i;
    int         l;
    int         sprite_number;

    i = 0;
    sprite_number = 0;
    sprites = malloc(sizeof(t_sprite) * n_sprites);
	while (g_check.map[i])
	{
		l = 0;
		while (l < g_check.n_columns)
		{
			if (g_check.map[i][l] == '4')
			{
                //sprites[sprite_number].num = sprite_number;
				sprites[sprite_number].x = i + 0.5;
				sprites[sprite_number].y = l + 0.5;
				sprite_number++;
			}
			l++;
		}
		i++;
	}
    return (0);
}

void    init_sprites (t_cub *cub)
{
	cub->sprite = (malloc(g_check.n_sprites * sizeof(t_sprite)));
	cub->s_cast.sprite_order = (int *)malloc(sizeof(int) * g_check.n_sprites);
	def_sprites(g_check.n_sprites);
	
	cub->s_cast.z_buffer = malloc(sizeof(double) * g_check.res_w); // Cambiar por h o w?
	//cub->s_cast.sprite_order = malloc(sizeof(int) * g_check.n_sprites);
	cub->s_cast.sprite_distance = malloc(sizeof(double) * g_check.n_sprites);
}
