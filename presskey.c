/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presskey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:34:53 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 13:34:54 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw_up(t_mapinfo *map)
{
    if (map->line[map->loc.x - 1][map->loc.y] == '1')
        return;
    if (map->line[map->loc.x - 1][map->loc.y] == 'E')
    {
        if (map->ccount != 0)
            return;
        else
            end_game(map);
    }
    if (map->line[map->loc.x - 1][map->loc.y] == 'C')
        map->ccount--;
    map->stepcnt++;
    printf("%d\n",map->stepcnt);    
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x - 1][map->loc.y] = 'P';
    map->loc.x--;
    draw_game(map->mlx, map->win, map);
}
void draw_down(t_mapinfo *map)
{
    if (map->line[map->loc.x + 1][map->loc.y] == '1')
        return;
    if (map->line[map->loc.x + 1][map->loc.y] == 'E')
    {
        if (map->ccount != 0)
            return;
        else
            end_game(map);
    }
    if (map->line[map->loc.x + 1][map->loc.y] == 'C')
        map->ccount--;
    map->stepcnt++;
    printf("%d\n",map->stepcnt);
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x + 1][map->loc.y] = 'P';
    map->loc.x++;
    draw_game(map->mlx, map->win, map);
}
void draw_left(t_mapinfo *map)
{
    if (map->line[map->loc.x][map->loc.y - 1] == '1')
        return;
    if (map->line[map->loc.x][map->loc.y - 1] == 'E')
    {
        if (map->ccount != 0)
            return;
        else
            end_game(map);
    }
    if (map->line[map->loc.x][map->loc.y - 1] == 'C')
        map->ccount--;
    map->stepcnt++;
    printf("%d\n",map->stepcnt);
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x][map->loc.y - 1] = 'P';
    map->loc.y--;
    draw_game(map->mlx, map->win, map);
}
void draw_right(t_mapinfo *map)
{
    if (map->line[map->loc.x][map->loc.y + 1] == '1')
        return;
    if (map->line[map->loc.x][map->loc.y + 1] == 'E')
    {
        if (map->ccount != 0)
            return;
        else
            end_game(map);
    }
    if (map->line[map->loc.x][map->loc.y + 1] == 'C')
        map->ccount--;
    map->stepcnt++;
    printf("%d\n",map->stepcnt);
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x][map->loc.y + 1] = 'P';
    map->loc.y++;
    draw_game(map->mlx, map->win, map);
}
int key_press(int keycode, t_mapinfo *map)
{

    if (keycode == KEY_W)
        draw_up(map);
    else if (keycode == KEY_S)
        draw_down(map);
    else if (keycode == KEY_A)
        draw_left(map);
    else if (keycode == KEY_D)
        draw_right(map);
    else if (keycode == KEY_ESC)
        exit(0);

    return (0);
}
