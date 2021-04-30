/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_moremap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 04:52:14 by carlos            #+#    #+#             */
/*   Updated: 2021/04/30 03:37:21 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		check_close_map(char **map, int row, int col)
{
	char	position;

	if (row < 0 || col < 0 || row >= g_check.n_rows
	|| col >= g_check.n_columns)
		print_error("Map is not closed");
	position = map[row][col];
	if (position == ' ')
		print_error("Map is not closed");
	else if (position == '3' || position == '1' || position == '4')
		return (0);
	else if (position == '2')
		map[row][col] = '4';
	else if (position == '0')
		map[row][col] = '3';
	check_close_map(map, row, col - 1);
	check_close_map(map, row, col + 1);
	check_close_map(map, row - 1, col);
	check_close_map(map, row + 1, col);
	return (0);
}

void	check_position(void)
{
	int		i;
	int		l;

	i = 0;
	while (g_check.map[i])
	{
		l = 0;
		while (l < g_check.n_columns)
		{
			if (ft_strchr("NESW", g_check.map[i][l]))
			{
				g_check.player_ori = g_check.map[i][l];
				g_check.player_x = i;
				g_check.player_y = l;
				g_check.n_player++;
			}
			l++;
		}
		i++;
	}
	g_check.n_rows = i;
}

//Añadidas recientemente RETOCAR
void	surrounded(int l, int j, char **maze)
{
	if ( (l < 1 || l == g_check.n_rows) || (maze[l - 1][l - 1] == ' ' 
		|| maze[l - 1][j - 1] == '\0') || (maze[l - 1][j + 1] == ' ' 
		|| maze[l - 1][j + 1] == '\0') || (maze[l + 1][j - 1] == ' ' 
		|| maze[l + 1][j - 1] == '\0') || (maze[l + 1][j + 1] == ' ' 
		|| maze[l + 1][j + 1] == '\0') || (maze[l][j + 1] == ' ' 
		|| maze[l][j + 1] == '\0') || (maze[l + 1][j] == ' ' 
		|| maze[l + 1][j] == '\0') || (maze[l][j - 1] == ' ' 
		|| maze[l][j - 1] == '\0') || (maze[l - 1][j] == ' ' 
		|| maze[l - 1][j] == '\0'))
	{
		print_error("Wrong map something is not surrounded by 1");
	}
}

void	gap(void)
{
	int l;
	size_t j;
	
	l = 0;
	j = 0;
	while (l < g_check.n_rows)
	{
		j = 0;
		while (j <= ft_strlen(g_check.map[l]))
		{
			if (g_check.map[l][j] == '0' || g_check.map[l][j] == '2' ||
				g_check.map[l][j] == 'N' || g_check.map[l][j] == 'S' || 
				g_check.map[l][j] == 'E' || g_check.map[l][j] == 'W')
				{
					surrounded(l, j, g_check.map);
				}
			j++;
		}
		l++;
	}
}

void	read_moremap(void)
{
	check_position();
	if (g_check.n_player < 1)
		print_error("There isn't any player on the map");
	if (g_check.n_player > 1)
		print_error("There are more than one player");
	gap();
	check_close_map(g_check.map, g_check.player_x, g_check.player_y);
}
