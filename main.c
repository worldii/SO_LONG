#include "so_long.h"

int main(void)
{
    void *mlx;
    void *win;
    void *img;
    void *img2;
    void *img3;
    t_param param;
    t_mapinfo map;
    param_init(&param);

    int img_width;
    int img_height;

    mlx = mlx_init();
    map_read(&map, "map_test.ber");

    win = mlx_new_window(mlx, map.width * 64, map.height * 64, "my_mlx");
    void *img_dino = mlx_xpm_file_to_image(mlx, "./images/dino2.xpm", &img_width, &img_height);
    void *img_apple = mlx_xpm_file_to_image(mlx, "./images/food2.xpm", &img_width, &img_height);
    void *img_exit = mlx_xpm_file_to_image(mlx, "./images/exit.xpm", &img_width, &img_height);
    void *img_fences = mlx_xpm_file_to_image(mlx, "./images/fence2.xpm", &img_width, &img_height);
    void *img_tile = mlx_xpm_file_to_image(mlx, "./images/grass.xpm", &img_width, &img_height);

    printf("%d %d", map.height, map.width);
    int hei;
    int wid;

    hei = 0;
    while (hei < map.height)
    {
        wid = 0;
        while (wid < map.width)
        {
            //            printf("%c", map.line[hei][wid]);

            if (map.line[hei][wid] == '1')
            {
                mlx_put_image_to_window(mlx, win, img_fences, wid * 64, hei * 64);
            }
            else if (map.line[hei][wid] == 'C')
            {
                mlx_put_image_to_window(mlx, win, img_apple, wid * 64, hei * 64);
            }
            else if (map.line[hei][wid] == 'P')
            {
                mlx_put_image_to_window(mlx, win, img_dino, wid * 64, hei * 64);
            }
            else if (map.line[hei][wid] == 'E')
            {
                mlx_put_image_to_window(mlx, win, img_exit, wid * 64, hei * 64);
            }
            else
            {
                mlx_put_image_to_window(mlx, win, img_tile, wid * 64, hei * 64);
            }
            wid++;
        }
        hei++;
    }

    // system("leaks so_long > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
    mlx_loop(mlx);
    mlx_hook(win, X_EVENT_KEY_RELEASE, 0, &key_press, &param);
}
