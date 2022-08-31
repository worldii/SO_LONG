/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:34:48 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 13:34:49 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_game(void *mlx, void *win, t_mapinfo *map)
{
	int	h;
	int	w;

	h = 0;
	while (h < map->h)
	{
		w = 0;
		while (w < map->w)
		{
			if (map->line[h][w] == '1')
				mlx_put_image_to_window(mlx, win, map->fences, w * 64, h * 64);
			else if (map->line[h][w] == 'C')
				mlx_put_image_to_window(mlx, win, map->apple, w * 64, h * 64);
			else if (map->line[h][w] == 'P')
				mlx_put_image_to_window(mlx, win, map->dino, w * 64, h * 64);
			else if (map->line[h][w] == 'E')
				drawe(mlx, map, w, h);
			else
				mlx_put_image_to_window(mlx, win, map->tile, w * 64, h * 64);
			w++;
		}
		h++;
	}
}

void	drawe(void *mlx, t_mapinfo *map, int w, int h)
{
	if (map->ccount == 0)
		mlx_put_image_to_window(mlx, map->win, map->exit2, w * 64, h * 64);
	else
		mlx_put_image_to_window(mlx, map->win, map->exit, w * 64, h * 64);
}

void	errormsg(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_mapinfo	map;

	if (argc != 2)
		errormsg("ARG MUST 2");
	map.mlx = mlx_init();
	map_read(&map, argv[1]);
	img_init(map.mlx, &map);
	check_map(&map);
	map.win = mlx_new_window(map.mlx, map.w * 64, map.h * 64, "so_long");
	draw_game(map.mlx, map.win, &map);
//	system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_map, &map);
	mlx_loop(map.mlx);
}
