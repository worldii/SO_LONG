#include "so_long.h"

void param_init(t_param *param)
{
    param->x = 3;
    param->y = 4;
}
void img_init(void *mlx, t_mapinfo *map)
{
    int img_width;
    int img_height;
    map->img_dino = mlx_xpm_file_to_image(mlx, "./images/dino2.xpm", &img_width, &img_height);
    map->img_apple = mlx_xpm_file_to_image(mlx, "./images/food2.xpm", &img_width, &img_height);
    map->img_exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &img_width, &img_height);
    map->img_fences = mlx_xpm_file_to_image(mlx, "./images/fence2.xpm", &img_width, &img_height);
    map->img_tile = mlx_xpm_file_to_image(mlx, "./images/grass2.xpm", &img_width, &img_height);
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
    /*
     */
}

void free_map(t_mapinfo *map)
{
    for (int i = 0; i < map->height; i++)
    {
        free(map->line[i]);
    }
    free(map->line);
}

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
                mlx_put_image_to_window(mlx, win, map->img_exit, wid * 64, hei * 64);
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