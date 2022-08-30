/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:31:22 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 05:17:37 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void img_init(void *mlx, t_mapinfo *map)
{
    int img_width;
    int img_height;
    map->img_dino = mlx_xpm_file_to_image(mlx, "./images/dino2.xpm", &img_width, &img_height);
    map->img_apple = mlx_xpm_file_to_image(mlx, "./images/food2.xpm", &img_width, &img_height);
    map->img_exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &img_width, &img_height);
    map->img_exit2 = mlx_xpm_file_to_image(mlx, "./images/exit2.xpm", &img_width, &img_height);
    map->img_fences = mlx_xpm_file_to_image(mlx, "./images/fence2.xpm", &img_width, &img_height);
    map->img_tile = mlx_xpm_file_to_image(mlx, "./images/grass2.xpm", &img_width, &img_height);
}

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

    map->line[map->loc.x][map->loc.y] = '0';
    map->line[map->loc.x - 1][map->loc.y] = 'P';
    map->loc.x--;
    draw_game(map->mlx, map->win, map);
}

void end_game(t_mapinfo *map)
{
    // 걷는 스텝 수 세야함
    exit(0);
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
        line = get_next_line(fd);
        map->line[i] = ft_strndup(line, 0, map->width);
        free(line);
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
                if (map->ccount == 0)
                {
                    mlx_put_image_to_window(mlx, win, map->img_exit2, wid * 64, hei * 64);
                }
                else
                {
                    mlx_put_image_to_window(mlx, win, map->img_exit, wid * 64, hei * 64);
                }
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

int exit_map(t_mapinfo *map)
{
    mlx_destroy_window(map->mlx, map->win);
    exit(0);
}

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
