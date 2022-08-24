#include "so_long.h"

int main(void)
{
    void *mlx;
    void *win;
    t_param param;
    t_mapinfo map;
    param_init(&param);

    int img_width;
    int img_height;

    mlx = mlx_init();
    map_read(&map, "map_test.ber");
    win = mlx_new_window(mlx, map.width * 64, map.height * 64, "my_mlx");
    img_init(mlx, &map);
    draw_game(mlx, win, &map);
    // system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    mlx_loop(mlx);
    mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
}
