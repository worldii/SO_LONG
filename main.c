#include "so_long.h"

int main(void)
{

    t_mapinfo map;

    int img_width;
    int img_height;

    map.mlx = mlx_init();
    map_read(&map, "map_test.ber");
    map.win = mlx_new_window(map.mlx, map.width * 64, map.height * 64, "my_mlx");
    img_init(map.mlx, &map);
    draw_game(map.mlx, map.win, &map);
    // system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
    mlx_loop(map.mlx);
}
