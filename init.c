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
	int	img_width;
	int	img_height;
	map->img_dino = mlx_xpm_file_to_image(mlx, "./images/dino2.xpm", &img_width, &img_height);
    map->img_apple = mlx_xpm_file_to_image(mlx, "./images/food2.xpm", &img_width, &img_height);
    map->img_exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &img_width, &img_height);
    map->img_exit2 = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &img_width, &img_height);
    map->img_fences = mlx_xpm_file_to_image(mlx, "./images/fence2.xpm", &img_width, &img_height);
    map->img_tile = mlx_xpm_file_to_image(mlx, "./images/grass2.xpm", &img_width, &img_height);
}
void map_read(t_mapinfo *map, char *filename)
{
    int fd;
    char *line;
    t_param *param = &(map->loc);

    fd = open(filename, O_RDONLY);
    if (fd <= 0)
        errormsg("File open fail.\n");
    line = get_next_line(fd);
    map->height = 0;
    map->width = ft_strlen(line) - 1;
    while (line)
    {
        free(line);
        map->height++;
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    fd = open(filename, O_RDONLY);
    map->line = (char **)malloc(sizeof(char *) * map->height);
    for (int i = 0; i < map->height; i++)
    {
        line = get_next_line(fd);
        map->line[i] = ft_strndup(line, 0, map->width);
        free(line);
        for (int j = 0; j < map->width; j++)
        {
            if (map->line[i][j] == 'P')
            {
                param->x = i;
                param->y = j;
                break;
            }
        }
    }

    close(fd);
}

void end_game(t_mapinfo *map)
{
    // 걷는 스텝 수 세야함
    exit(0);
}
void free_map(t_mapinfo *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->line[i]);
    }
    free(map->line);
}
int exit_map(t_mapinfo *map)
{
    mlx_destroy_window(map->mlx, map->win);
    exit(0);
}
