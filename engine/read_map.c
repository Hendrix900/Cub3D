/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 01:18:39 by carlos            #+#    #+#             */
/*   Updated: 2021/02/28 03:27:43 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void check_line_map(char *line)
{
    int l;

    l = 0;
    while (line[l] != '\0')
        {
            if (!(ft_strchr("NESW012\t ",line[l])))
		        print_error("Wrong map");
        l++;
        }
    g_check.n_rows++;    
    if (l > g_check.n_columns)
	    g_check.n_columns = l;    
    printf("la cadena contiene : %s\n", line);
}

void    read_map(int fd)
{
    char *line;
    char dev;
    int l;

    l = 0;
    
    while (dev = get_next_line(fd, &line) > 0)
    {
        check_line_map(line);
        free(line);
    }   
}