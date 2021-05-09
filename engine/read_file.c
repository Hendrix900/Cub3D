/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 20:05:23 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/09 20:27:34 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_line3(char *line, char *position, int l, t_cub *cub)
{
	if ((ft_strnstr(line, "F", ft_strlen(line))) && cub->cf.param_f == 0)
	{
		position = ft_strnstr(line, "F", ft_strlen(line));
		extract_color_floor(line, position, cub);
		cub->cf.param_f = 1;
		return (0);
	}
	else if ((ft_strnstr(line, "C", ft_strlen(line))) && cub->cf.param_c == 0)
	{
		position = ft_strnstr(line, "C", ft_strlen(line));
		extract_color_celing(line, position, cub);
		cub->cf.param_c = 1;
		return (0);
	}
	else
	{
		while (line[l] != '\0')
		{
			if (!(ft_strchr("\t ", line[l])) && (cub->cf.error != 1))
				free_print_error("Wrong or repeated parameter", cub);
			l++;
		}
	}
}

int	check_line2(char *line, char *position, int l, t_cub *cub)
{
	if ((ft_strnstr(line, "WE", ft_strlen(line))) && cub->cf.param_we == 0)
	{
		position = ft_strnstr(line, "WE", ft_strlen(line));
		cub->cf.texture_we = extract_texture(line, position, cub);
		cub->cf.param_we = 1;
		return (0);
	}
	else if ((ft_strnstr(line, "EA", ft_strlen(line))) && cub->cf.param_ea == 0)
	{
		position = ft_strnstr(line, "EA", ft_strlen(line));
		cub->cf.texture_ea = extract_texture(line, position, cub);
		cub->cf.param_ea = 1;
		return (0);
	}
	else if ((ft_strnstr(line, "S", ft_strlen(line))) && cub->cf.param_s == 0)
	{
		position = ft_strnstr(line, "S", ft_strlen(line));
		cub->cf.texture_s = extract_texture_sprite(line, position, cub);
		cub->cf.param_s = 1;
		return (0);
	}
	check_line3(line, position, l, cub);
}

int	check_line(char *line, char *position, int l, t_cub *cub)
{
	if ((ft_strnstr(line, "R", ft_strlen(line))) && cub->cf.param_r == 0)
	{
		position = ft_strnstr(line, "R", ft_strlen(line));
		extract_resolution(line, position, cub);
		cub->cf.param_r = 1;
		return (0);
	}
	else if ((ft_strnstr(line, "NO", ft_strlen(line))) && cub->cf.param_no == 0)
	{
		position = ft_strnstr(line, "NO", ft_strlen(line));
		cub->cf.texture_no = extract_texture(line, position, cub);
		cub->cf.param_no = 1;
		return (0);
	}
	else if ((ft_strnstr(line, "SO", ft_strlen(line))) && cub->cf.param_so == 0)
	{
		position = ft_strnstr(line, "SO", ft_strlen(line));
		cub->cf.texture_so = extract_texture(line, position, cub);
		cub->cf.param_so = 1;
		return (0);
	}
	check_line2(line, position, l, cub);
}

void	init_conf(t_cub *cub)
{
	cub->cf.count_parameters = 0;
	cub->cf.param_r = 0;
	cub->cf.param_no = 0;
	cub->cf.param_so = 0;
	cub->cf.param_s = 0;
	cub->cf.param_ea = 0;
	cub->cf.param_c = 0;
	cub->cf.param_we = 0;
	cub->cf.param_f = 0;
	cub->cf.error = 0;
	cub->cf.buffer = NULL;
	cub->cf.n_columns = 0;
	cub->cf.n_player = 0;
}

void	read_file(char *argv, t_cub *cub)
{
	int		fd;
	char	*line;
	char	*position;
	int		l;

	l = 0;
	position = NULL;
	init_conf(cub);
	fd = open(argv, O_RDONLY);
	if ((fd <= 0))
		print_error_arg("Is not possible to open the FD");
	while (get_next_line(fd, &line) > 0 && cub->cf.count_parameters < 8)
	{
		check_line(line, position, l, cub);
		free(line);
	}
	if (cub->cf.count_parameters == 0)
	{
		free(line);
		print_error_arg("The file is wrong");
	}
	if (cub->cf.count_parameters != 8)
		free_print_error("The number of parameters in the file are wrong", cub);
	read_map(fd, line, cub);
}
