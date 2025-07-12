/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:02:52 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/12 20:06:50 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define WIN_HEIGHT 500
#define WIN_WIDTH 500

/**
 * 	this struct contains information about an image
 */
typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

/**
 *  this struct contains all the mlx stuff
 * 	and the image where we buffer pixels
 */
typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_img img;
} t_mlx_data;

// handler function - every time a key is pressed this function is called
int handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("the %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(1);
	}
	printf("the %d key has been pressed\n\n", keysym);
}

void my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
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

void write_circle(t_img *img, int x_center, int y_center, int r, int color)
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
			if (ft_sqrt((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center)) == r)
				my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
	my_mlx_pixel_put(img, x_center, y_center, 0x0000FF00);
}

int main(void)
{
	t_mlx_data data;

	// opening connection
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (1);
	// creating window
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "so_long prep");
	if (data.win_ptr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	// creating image to which we buffer pixels
	data.img.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);

	/**
	 * HOOKS
	 * hook into event (react to event)
	 *
	 */
	mlx_key_hook(data.win_ptr, handle_input, &data);

	// putting image to window
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 0, 0);

	// loop in which process keep listening for events
	mlx_loop(data.mlx_ptr);

	// writing circle
	int i = 15;
	while (i <= 120)
	{
		if (i % 2)
			write_circle(data.img.img, 250, 250, i, 0x00FF0000);
		else
			write_circle(data.img.img, 250, 250, i, 0x0000FF00);
		i += 15;
	}

	// clean up section
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr); // frees display before exit
	free(data.mlx_ptr);
}