#include "so_long.h"

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
void draw_up(t_mapinfo *map)
{
    if (map->line[map->loc.x - 1][map->loc.y] == '1')
        return;
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x - 1][map->loc.y] = 'P';
    map->loc.x--;
    draw_game(map->mlx, map->win, map);
}
void draw_down(t_mapinfo *map)
{
    if (map->line[map->loc.x + 1][map->loc.y] == '1')
        return;
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x + 1][map->loc.y] = 'P';
    map->loc.x++;
    draw_game(map->mlx, map->win, map);
}

void draw_left(t_mapinfo *map)
{
    if (map->line[map->loc.x][map->loc.y - 1] == '1')
        return;
    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x][map->loc.y - 1] = 'P';
    map->loc.y--;
    draw_game(map->mlx, map->win, map);
}
void draw_right(t_mapinfo *map)
{
    if (map->line[map->loc.x][map->loc.y + 1] == '1')
        return;
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

void map_read(t_mapinfo *map, char *filename)
{
    int fd;
    char *line;
    t_param *param = &(map->loc);

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
        for (int j = 0; j < map->width; j++)
        {
            if (map->line[i][j] == 'P')
            {
                param->x = i;
                param->y = j;
                break;
            }
        }
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