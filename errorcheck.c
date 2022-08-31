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

void	check_map(t_mapinfo	*map)
{
	rec_check(map);
	wall_check(map);
	count_check(map);
}

void	rec_check(t_mapinfo *map)
{
	int	i;

	i = -1;
	while (++i < map->h)
	{
		if (ft_strlen(map->line[i]) != map->w)
			errormsg("RECTANGULAR ERROR");
	}
}

void	wall_check(t_mapinfo	*map)
{
	int	i;

	i = -1;
	while (++i < map->w)
	{
		if (map->line[0][i] != '1' || map->line[map->h - 1][i] != '1')
			errormsg("WALL ERROR");
	}
	i = -1;
	while (++i < map->h - 1)
	{
		if (map->line[i][0] != '1' || map->line[i][map->w - 1] != '1')
			errormsg("WALL ERROR");
	}
}

void	count_check(t_mapinfo	*map)
{
	int	pcount;
	int	ecount;
	int	i;
	int	j;

	pcount = 0;
	ecount = 0;
	i = -1;
	map->ccount = 0;
	map->stepcnt = 0;
	while (++i < map->h)
	{
		j = -1;
		while (++j < map->w)
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
