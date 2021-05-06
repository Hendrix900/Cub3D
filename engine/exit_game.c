/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:07:25 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/06 23:22:14 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		exit_game(t_cub *cub)
{
	free_split(g_check.map);
	free(cub->sprite);
	free(cub->s_cast.sprite_order);
	free(g_check.texture_ea);
	free(g_check.texture_no);
	free(g_check.texture_so);
	free(g_check.texture_we);
	free(g_check.texture_s);
	mlx_destroy_image(cub->mlx.ptr, cub->mlx.image);
	mlx_destroy_image(cub->mlx.ptr, cub->texture.p_no);
	mlx_destroy_image(cub->mlx.ptr, cub->texture.p_so);
	mlx_destroy_image(cub->mlx.ptr, cub->texture.p_ea);
	mlx_destroy_image(cub->mlx.ptr, cub->texture.p_we);
	mlx_destroy_image(cub->mlx.ptr, cub->texture.p_sp);
	mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
	mlx_destroy_display(cub->mlx.ptr);
	free(cub->mlx.ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void	check_exit_texture(char *str, t_cub *cub)
{
	if (ft_strnstr(str, "WE", ft_strlen(str)))
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_no);
	else if (ft_strnstr(str, "SO", ft_strlen(str)))
	{
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_no);
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_we);
	}
	else if (ft_strnstr(str, "EA", ft_strlen(str)))
	{
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_no);
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_we);
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_so);
	}
	else if (ft_strnstr(str, "sprite", ft_strlen(str)))
	{
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_no);
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_we);
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_so);
		mlx_destroy_image(cub->mlx.ptr, cub->texture.p_ea);
	}
}

int		exit_game_texture(char *str, t_cub *cub)
{
	char *s2;

	free_split(g_check.map);
	free(g_check.texture_ea);
	free(g_check.texture_no);
	free(g_check.texture_so);
	free(g_check.texture_we);
	free(g_check.texture_s);
	mlx_destroy_image(cub->mlx.ptr, cub->mlx.image);
	check_exit_texture(str, cub);
	mlx_destroy_window(cub->mlx.ptr, cub->mlx.win);
	mlx_destroy_display(cub->mlx.ptr);
	free(cub->mlx.ptr);
	s2 = ft_strjoin("Error\n", str);
	perror(s2);
	free(s2);
	exit(EXIT_FAILURE);
}
