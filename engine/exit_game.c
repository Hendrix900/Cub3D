/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 19:07:25 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/09 19:39:54 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_game(t_cub *cub)
{
	free_split(cub->cf.map);
	free(cub->sprite);
	free(cub->s_cast.sprite_order);
	free(cub->cf.texture_ea);
	free(cub->cf.texture_no);
	free(cub->cf.texture_so);
	free(cub->cf.texture_we);
	free(cub->cf.texture_s);
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

int	exit_game_texture(char *str, t_cub *cub)
{
	char	*s2;

	free_split(cub->cf.map);
	free(cub->cf.texture_ea);
	free(cub->cf.texture_no);
	free(cub->cf.texture_so);
	free(cub->cf.texture_we);
	free(cub->cf.texture_s);
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
