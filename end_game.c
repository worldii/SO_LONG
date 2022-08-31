/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapa <jonghapa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:56:37 by jonghapa          #+#    #+#             */
/*   Updated: 2022/08/31 18:56:40 by jonghapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
