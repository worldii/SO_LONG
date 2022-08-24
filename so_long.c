#include "so_long.h"

void param_init(t_param *param)
{
    param->x = 3;
    param->y = 4;
}

int key_press(int keycode, t_param *param)
{
    static int a = 0;

    if (keycode == KEY_W)
        param->y++;
    else if (keycode == KEY_S)
        param->y--;
    else if (keycode == KEY_A)
        param->x--;
    else if (keycode == KEY_D)
        param->x++;
    else if (keycode == KEY_ESC)
        exit(0);
    printf("x: %d, y: %d\n", param->x, param->y);
    return (0);
}

void map_read(t_mapinfo *map, char *filename)
{
    int fd;
    char *line;

    fd = open(filename, O_RDONLY);
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
        map->line[i] = get_next_line(fd);
    }
    close(fd);
}

void free_map(t_mapinfo *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->line[i]);
    }
    free(map->line);
}
