/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <jonghapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:31:21 by jonghapark        #+#    #+#             */
/*   Updated: 2022/09/02 14:28:00 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(void *mlx, t_mapinfo *map)
{
	int	w;
	int	h;

	map->dino = mlx_xpm_file_to_image(mlx, "./images/dino2.xpm", &w, &h);
	map->apple = mlx_xpm_file_to_image(mlx, "./images/food2.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &w, &h);
	map->exit2 = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &w, &h);
	map->fences = mlx_xpm_file_to_image(mlx, "./images/fence2.xpm", &w, &h);
	map->tile = mlx_xpm_file_to_image(mlx, "./images/grass2.xpm", &w, &h);
}

void	map_read(t_mapinfo *map, char *filename)
{
	int		fd;
	char	*line;
	t_param	*param;

	param = &(map->loc);
	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		errormsg("File open fail.\n");
	line = get_next_line(fd);
	map->h = 0;
	map->w = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		map->h++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	fd = open(filename, O_RDONLY);
	map->line = (char **)malloc(sizeof(char *) * map->h);
	set_param(map, param, line, fd);
	close(fd);
}

static int	is_newline(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			return (i);
	}
	return (-1);
}

void	set_param(t_mapinfo *map, t_param *param, char *line, int fd)
{
	int	i;
	int	j;
	int	idx;

	i = -1;
	while (++i < map->h)
	{
		line = get_next_line(fd);
		idx = is_newline(line);
		if (idx == -1)
			map->line[i] = ft_strndup(line, 0, ft_strlen(line));
		else
			map->line[i] = ft_strndup(line, 0, idx);
		free(line);
		j = -1;
		while (++j < map->w)
		{
			if (map->line[i][j] == 'P')
			{
				param->x = i;
				param->y = j;
				break ;
			}
		}
	}
}
