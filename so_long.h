/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghapark <jonghapark@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 03:31:26 by jonghapark        #+#    #+#             */
/*   Updated: 2022/08/31 04:52:39 by jonghapark       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "./mlx/mlx.h"
#define X_EVENT_KEY_PRESS 2
#define X_EVENT_KEY_RELEASE 3
#define X_EVENT_KEY_EXIT 17
#include <fcntl.h>
#include "Libft/libft.h"
#include <unistd.h>
#include <stdio.h> 
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
    int h;
    int w;
    int ccount;
    int stepcnt;
    char **line;
    void *dino;
    void *apple;
    void *exit;
    void *exit2;
    void *fences;
    void *tile;
    void *mlx;
    void *win;
    t_param loc;

} t_mapinfo;

void map_read(t_mapinfo *map, char *filename);
void img_init(void *mlx, t_mapinfo *map);
void param_init(t_param *param);
int key_press(int keycode, t_mapinfo *map);
void draw_game(void *mlx, void *win, t_mapinfo *map);
int exit_map(t_mapinfo *map);
void errormsg(char *message);
void check_map(t_mapinfo *map);
void rec_check(t_mapinfo *map);
void count_check(t_mapinfo *map);
void wall_check(t_mapinfo *map);
void end_game(t_mapinfo *map);
void free_map(t_mapinfo *map);
void drawe (void *mlx, t_mapinfo *map, int w, int h);
void	set_param(t_mapinfo	*map, t_param	*param, char	*line, int fd);
#endif
