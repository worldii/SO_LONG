/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:31:21 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 13:39:51 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(void	*mlx, t_mapinfo	*map)
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
	/*for (int i = 0; i < map->h; i++)
    {
        line = get_next_line(fd);
        map->line[i] = ft_strndup(line, 0, map->w);
        free(line);
		for (int j = 0; j < map->w; j++)
		{
            if (map->line[i][j] == 'P')
			{
                param->x = i;
                param->y = j;
                break ;
			}
		}
	}*/
	set_param();
	close(fd);
}

void	set_param(t_mapinfo	*map, t_param	*param)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->h)
	{
		line = get_next_line(fd);
		map->line[i] = ft_strndup(line, 0, map->w);
		free(line);
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

void	end_game(t_mapinfo *map)
{
	map->stepcnt++;
	printf("GAME CLEAR ! ALL STEPS : %d\n", map->stepcnt);
	free_map(map);
	exit_map(map);
}

void	free_map(t_mapinfo *map)
{
	int	i;

	i = -1;
	while (++i < map->h)
		free(map->line[i]);
	free(map->line);
}

int	exit_map(t_mapinfo *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit (0);
}
