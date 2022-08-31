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