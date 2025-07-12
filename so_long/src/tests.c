#include "../include/so_long.h"

typedef struct s_data{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_data;


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}   

int ft_sqrt(int num)
{
    int res;

    res = 0;
    while (res * res <= num)
        res++;
    if (res * res > num)
        res--;
    return (res);
}

void write_circle(t_data *img, int x_center, int y_center, int r, int color)
{
    int x_start = x_center - r;
    int y_start = y_center - r;
    int x = x_start;
    int y = y_start;

    while (y <= 2 * r + y_start)
    {
        x = x_start;
        while (x <= 2 * r + x_start)
        {
            if (ft_sqrt((x - x_center)*(x - x_center) + (y - y_center)*(y - y_center)) == r)
                my_mlx_pixel_put(img, x, y, color);
            x++;
        }
        y++;
    }
    my_mlx_pixel_put(img, x_center, y_center, 0x0000FF00);
}

int create_trgb(int t, int r, int g, int b)
{
    return (t << 24 | r << 16 | g << 8 | b);
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    t_data img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "hello world again");
    img.img = mlx_new_image(mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
        &img.endian);

    //my_mlx_pixel_put(&img, 50, 50, 0x00FF0000);

    int i = 15;
    while (i <= 120){
        if (i % 2)
            write_circle(&img, 250, 250, i, 0x00FF0000);
        else
            write_circle(&img, 250, 250, i, 0x0000FF00);
        i+=15;
    }


    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}