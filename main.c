/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:31:16 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 05:07:28 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
