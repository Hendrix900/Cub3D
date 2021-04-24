/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 05:04:14 by ccastill          #+#    #+#             */
/*   Updated: 2021/04/24 21:29:32 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void    sprite_order_distance(t_cub *cub)
{
    int     tmp;
    int     dis_tmp;
    int     l;

    l = 0;
    while (l < g_check.n_sprites - 1)
    {
        if (cub->s_cast.sprite_distance[l] < cub->s_cast.sprite_distance[l + 1])
        {
            dis_tmp = cub->s_cast.sprite_distance[l + 1];
            cub->s_cast.sprite_distance[l + 1] = cub->s_cast.sprite_distance[l];
            cub->s_cast.sprite_distance[l] = dis_tmp;
            tmp = cub->s_cast.sprite_order[l + 1];
            cub->s_cast.sprite_order[l + 1] = cub->s_cast.sprite_order[l];
            cub->s_cast.sprite_order[l] = tmp;
            l = 0;
        }
            l++;        
    }
}

void    sprite_distance(t_cub *cub) // Llamarlo mejor algo de distancia
{
    int     l;
    
    l = 0;
    while (l < g_check.n_sprites)
    {
        cub->s_cast.sprite_order[l] = l;
        cub->s_cast.sprite_distance[l] = ((cub->player.pos_x - 
        cub->sprite[l].x) *
        (cub->player.pos_x - cub->sprite[l].x) + 
        (cub->player.pos_y - cub->sprite[l].y) * 
        (cub->player.pos_y - cub->sprite[l].y));
        l++;
    }
    sprite_order_distance(cub);
}

void    calculate_sprite(t_cub *cub, t_sprite_cas *scast)
{
    scast->h = abs((int)(g_check.res_h / (scast->transform_y)));
    scast->draw_end_y = -scast->h / 2 + g_check.res_h / 2;
    if (scast->draw_start_y < 0)
        scast->draw_start_y = 0;
    scast->draw_end_y = scast->h / 2 + g_check.res_h / 2;
    if (scast->draw_end_y >= g_check.res_h)
        scast->draw_end_y = g_check.res_h - 1;
	scast->w = abs((int)(g_check.res_h  / (scast->transform_y)));
    scast->draw_start_x = -scast->w / 2 + scast->screen_x;
    if (scast->draw_start_x < 0)
        scast->draw_start_x = 0;
    scast->draw_end_x = scast->w / 2 + scast->screen_x;
    if (scast->draw_end_x >= g_check.res_w)
        scast->draw_end_x = g_check.res_w - 1;    
}

void    paint_sprite(t_cub *cub, t_sprite_cas *scast, int stripe)
{
    scast->tex_x = (int)(256 * (stripe - (-scast->w / 2 + scast->screen_x))
        * cub->texture.sp_w / scast->w) / 256;
    if (scast->transform_y > 0 && stripe > 0 && stripe < g_check.res_w && 
    scast->transform_y < scast->z_buffer[stripe])
    {
        scast->y = scast->draw_start_y;
        while (scast->y < scast->draw_end_y)
        {
            scast->d = (scast->y) * 256 - g_check.res_w * 128 + scast->h * 128;
            scast->tex_y = ((scast->d * cub->texture.sp_h) / scast->h / 256);
            if (cub->texture.data_sp[scast->tex_x + scast->tex_y * 
                cub->texture.sp_sl / 4])
                cub->mlx.data[(int)(scast->stripe + scast->y * 
                cub->mlx.size_lenght / 4)] = 
                    cub->texture.data_sp[scast->tex_x + scast->tex_y
                    * cub->texture.sp_sl / 4];
        }
    }
}

void     raycasting_sprite(t_cub *cub)
{
    int                 l;
    int                 stripe;
    t_sprite_cas        scast;
    t_sprite            s;
    
    l = 0;
    sprite_distance(cub);
    while (l < g_check.n_sprites)
    {
        //--Arreglar esto--/
        /*
        scast.x = cub->sprite[scast.sprite_order[l]].x - cub->player.pos_x;
        scast.y = cub->sprite[scast.sprite_order[l]].y - cub->player.pos_y;
        */
        //-----//
        s = cub->sprite[scast.sprite_order[l]];
        scast.x = ((s.x) - cub->player.pos_x);
        scast.y = ((s.y) - cub->player.pos_y);
        scast.inv_det = 1.0 / (cub->player.plane_x * cub->player.dir_y - 
            cub->player.dir_x * cub->player.plane_y);
        scast.transform_x = scast.inv_det * (cub->player.dir_y * 
            scast.x - cub->player.dir_x * scast.y);
        scast.transform_y = scast.inv_det * (-cub->player.plane_y *
            scast.x + cub->player.plane_x * scast.y);
        scast.screen_x = (int)((g_check.res_w / 2) *
            (1 + scast.transform_x / scast.transform_y));
        calculate_sprite(cub, &scast);
        stripe = scast.draw_start_x;
        while (stripe < scast.draw_end_x)
        {
            paint_sprite(cub, &scast, stripe);
            stripe++;
        }
        l++;
    }
}