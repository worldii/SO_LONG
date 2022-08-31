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
    count_check(map);
    wall_check(map);
}

void rec_check(t_mapinfo *map)
{
    for (int i = 0; i < map->height; i++)
    {
        // printf("%d %d ", ft_strlen(map->line[i]), map->width);
        if (ft_strlen(map->line[i]) != map->width)
            errormsg("RECTANGULAR ERROR");
    }
}
void wall_check(t_mapinfo *map)
{
    // 상하좌우 벽으류
    for (int i = 0; i < map->width; i++)
    {
        if (map->line[0][i] != '1' || map->line[map->height - 1][i] != '1')
            errormsg("WALL ERROR");
    }

    for (int i = 1; i < map->height - 1; i++)
    {
        if (map->line[i][0] != '1' || map->line[i][map->width - 1] != '1')
            errormsg("WALL ERROR");
    }
}
void count_check(t_mapinfo *map)
{
    int pcount = 0;
    int ecount = 0;
    map->ccount = 0;
    for (int i = 0; i < map->height; i++)
    {
        for (int j = 0; j < map->width; j++)
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
