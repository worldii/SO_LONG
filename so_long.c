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

void draw_game(void *mlx, void *win, t_mapinfo *map)
{
    int hei;
    int wid;

    hei = 0;
    while (hei < map->height)
    {
        wid = 0;
        while (wid < map->width)
        {
            if (map->line[hei][wid] == '1')
            {
                mlx_put_image_to_window(mlx, win, map->img_fences, wid * 64, hei * 64);
            }
            else if (map->line[hei][wid] == 'C')
            {
                mlx_put_image_to_window(mlx, win, map->img_apple, wid * 64, hei * 64);
            }
            else if (map->line[hei][wid] == 'P')
            {
                mlx_put_image_to_window(mlx, win, map->img_dino, wid * 64, hei * 64);
            }
            else if (map->line[hei][wid] == 'E')
            {
                if (map->ccount == 0)
                {
                    mlx_put_image_to_window(mlx, win, map->img_exit2, wid * 64, hei * 64);
                }
                else
                {
                    mlx_put_image_to_window(mlx, win, map->img_exit, wid * 64, hei * 64);
                }
            }
            else
            {
                mlx_put_image_to_window(mlx, win, map->img_tile, wid * 64, hei * 64);
            }
            wid++;
        }
        hei++;
    }
}

void errormsg(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    exit(1);
}

int main(int argc, char *argv[])
{

    t_mapinfo map;
    if (argc != 2)
        errormsg("ARG MUST 2");
    map.mlx = mlx_init();
    map_read(&map, argv[1]);
    img_init(map.mlx, &map);
    check_map(&map);
    // MAP ERROR 처리 필요함 (직사각형, wall로 둘러싸여있는 것, 적어도 하나 exit, 수집 존재, 1개만의 시작 위치),
    map.win = mlx_new_window(map.mlx, map.width * 64, map.height * 64, "my_mlx");
    draw_game(map.mlx, map.win, &map);
    system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
    mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_map, &map);
    mlx_loop(map.mlx);
}
