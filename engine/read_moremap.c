/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_moremap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 04:52:14 by carlos            #+#    #+#             */
/*   Updated: 2021/03/05 06:23:21 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     check_close_map(char **map, int row, int col)
{
	char		c;
	int			ok;
    int         l;
    l = 0;    
	if (row < 0 || col < 0 || row >= g_check.n_rows
	|| col >= g_check.n_columns)
		return (1);
	c = map[row][col];
	if (c == ' ')
		return (1);
	else if (c == '3' || c == '1')
		return (0);
	map[row][col] = '3';
      /*  while (g_check.map[l])
    {
        printf("el contenido de g_check.map tras split  [%d] es %s\n",l ,g_check.map[l]);
        l++;
    }  */
    //printf("Entra en colum <-\n");
	ok = check_close_map(map, row, col - 1);
    //printf("Entra en colum ->\n");
	ok = ok == 0 ? check_close_map(map, row, col + 1) : ok;
    //printf("Entra en row ARRIBA\n");
	ok = ok == 0 ? check_close_map(map, row - 1, col) : ok;
    //printf("Entra en row ABAJO\n");
	ok = ok == 0 ? check_close_map(map, row + 1, col) : ok;
    //printf("SE VA\n");
	return (ok);
}


void    check_position()
{
    int i;
    int l;

    i = 0;
    while (g_check.map[i])
    {
        l = 0;
        while (l < g_check.n_columns)
        {
            if (ft_strchr("NESW", g_check.map[i][l]))
            {
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

void    read_moremap()
{
    check_position();
    if (g_check.n_player < 1)
        print_error("There isn't any player on the map");
    if (g_check.n_player > 1)
        print_error("There are more than one player");    
    if (check_close_map(g_check.map, g_check.player_x, g_check.player_y))
		print_error("Map is not closed");
}