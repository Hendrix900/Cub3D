/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_moremap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 04:52:14 by carlos            #+#    #+#             */
/*   Updated: 2021/05/10 22:17:12 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_close_map(char **map, int row, int col, t_cub *cub)
{
	char	position;

	if (row < 0 || col < 0 || row >= cub->cf.n_rows
		|| col >= cub->cf.n_columns)
		print_error("Map is not closed", cub);
	position = map[row][col];
	if (position == ' ')
		print_error("Map is not closed", cub);
	else if (position == '3' || position == '1' || position == '4')
		return (0);
	else if (position == '2')
		map[row][col] = '4';
	else if (position == '0')
		map[row][col] = '3';
	check_close_map(map, row, col - 1, cub);
	check_close_map(map, row, col + 1, cub);
	check_close_map(map, row - 1, col, cub);
	check_close_map(map, row + 1, col, cub);
	return (0);
}

void	check_position(t_cub *cub)
{
	int	i;
	int	l;

	i = 0;
	while (cub->cf.map[i])
	{
		l = 0;
		while (l < cub->cf.n_columns)
		{
			if (ft_strchr("NESW", cub->cf.map[i][l]))
			{
				cub->cf.player_ori = cub->cf.map[i][l];
				cub->cf.player_x = i;
				cub->cf.player_y = l;
				cub->cf.n_player++;
			}
			l++;
		}
		i++;
	}
	cub->cf.n_rows = i;
}

void	surround_by_one(int l, int j, char **map, t_cub *cub)
{
	if ((l < 1 || (l == cub->cf.n_rows - 1 || j < 1)
			|| (map[l - 1][j - 1] == ' ' || map[l - 1][j - 1] == '\0')
		|| (map[l - 1][j + 1] == ' ' || map[l - 1][j + 1] == '\0')
		|| (map[l + 1][j - 1] == ' ' || map[l + 1][j - 1] == '\0')
		|| (map[l + 1][j + 1] == ' ' || map[l + 1][j + 1] == '\0')
		|| (map[l][j + 1] == ' ' || map[l][j + 1] == '\0')
		|| (map[l + 1][j] == ' ' || map[l + 1][j] == '\0')
		|| (map[l][j - 1] == ' ' || map[l][j - 1] == '\0')
		|| (map[l - 1][j] == ' ' || map[l - 1][j] == '\0')))
	{
		print_error("Wrong map, something is not surrounded by 1", cub);
	}
}

void	check_surround_by_one(t_cub *cub)
{
	int		l;
	size_t	j;

	l = 0;
	j = 0;
	while (l < cub->cf.n_rows)
	{
		j = 0;
		while (j <= ft_strlen(cub->cf.map[l]))
		{
			if (cub->cf.map[l][j] == '0'
				|| cub->cf.map[l][j] == '2'
				|| cub->cf.map[l][j] == 'N'
				|| cub->cf.map[l][j] == 'S'
				|| cub->cf.map[l][j] == 'E'
				|| cub->cf.map[l][j] == 'W')
				surround_by_one(l, j, cub->cf.map, cub);
			j++;
		}
		l++;
	}
}

void	read_moremap(t_cub *cub)
{
	check_position(cub);
	if (cub->cf.n_player < 1)
		print_error("There isn't any player on the map", cub);
	if (cub->cf.n_player > 1)
		print_error("There are more than one player", cub);
	check_surround_by_one(cub);
	check_close_map(cub->cf.map, cub->cf.player_x, cub->cf.player_y, cub);
}
