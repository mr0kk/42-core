/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:02:52 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/12 23:15:15 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

// handler function - every time a key is pressed this function is called
int handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("the %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_image(data->mlx_ptr, data->img.img);
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

void	circle_shield(t_img *img)
{
	int i = 15;
	while (i <= 120)
	{
		if (i % 2)
			write_circle(img, 250, 250, i, 0x00FF0000);
		else
			write_circle(img, 250, 250, i, 0x0000FF00);
		i += 15;
	}
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
		free(data.win_ptr);
		return (1);
	}
	// creating image to which we buffer pixels
	data.img.img = mlx_new_image(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (data.img.img == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		free(data.mlx_ptr);
		return (1);
	}
	data.img.addr = mlx_get_data_addr(data.img.img, &data.img.bits_per_pixel, &data.img.line_length, &data.img.endian);
	if (data.img.addr == NULL)
	{
		mlx_destroy_display(data.mlx_ptr);
		mlx_destroy_image(data.mlx_ptr, data.img.img);
		free(data.mlx_ptr);
		return (1);
	}
	/**
	 * HOOKS
	 * hook into event (react to event)
	 *
	 */
	mlx_key_hook(data.win_ptr, handle_input, &data);

	// writing circle
	circle_shield(&data.img);

	// putting image to window
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img, 0, 0);

	// loop in which process keep listening for events
	mlx_loop(data.mlx_ptr);

	// clean up section
	mlx_destroy_image(data.mlx_ptr, data.img.img);
	mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}