/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:31:30 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 13:35:01 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map(t_mapinfo *map)
{
    rec_check(map);
    wall_check(map);
    count_check(map);
}

void rec_check(t_mapinfo *map)
{
    for (int i = 0; i < map->h; i++)
    {
        if (ft_strlen(map->line[i]) != map->w)
            errormsg("RECTANGULAR ERROR");
    }
}
void wall_check(t_mapinfo *map)
{
    for (int i = 0; i < map->w; i++)
    {
        if (map->line[0][i] != '1' || map->line[map->h - 1][i] != '1')
            errormsg("WALL ERROR");
    }

    for (int i = 1; i < map->h - 1; i++)
    {
        if (map->line[i][0] != '1' || map->line[i][map->w - 1] != '1')
            errormsg("WALL ERROR");
    }
}
void count_check(t_mapinfo *map)
{
    int pcount = 0;
    int ecount = 0;
    map->ccount = 0;
    map->stepcnt = 0;
    for (int i = 0; i < map->h; i++)
    {
        for (int j = 0; j < map->w; j++)
        {
            if (map->line[i][j] == 'E')
                ecount++;
            else if (map->line[i][j] == 'P')
                pcount++;
            else if (map->line[i][j] == 'C')
                map->ccount++;
            else if (map->line[i][j] != '1' && map->line[i][j] != '0')
                errormsg("Component ERROR");
        }
    }

    if (ecount < 1 || pcount != 1 || map->ccount < 1)
        errormsg("Component ERROR");
}
