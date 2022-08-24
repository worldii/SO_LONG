#ifndef SO_LONG_H
#define SO_LONG_H

#include "../mlx/mlx.h"
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h> // 빼야할듯..
#include <stdlib.h>
#include "get_next_line.h"
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2

typedef struct s_param
{
    int x;
    int y;
} t_param;

typedef struct s_mapinfo
{
    int height;
    int width;
    char **line;
    void *img_dino;
    void *img_apple;
    void *img_exit;
    void *img_fences;
    void *img_tile;

} t_mapinfo;
void map_read(t_mapinfo *map, char *filename);
void img_init(void *mlx, t_mapinfo *map);
void param_init(t_param *param);
int key_press(int keycode, t_param *param);
void draw_game(void *mlx, void *win, t_mapinfo *map);
#endif