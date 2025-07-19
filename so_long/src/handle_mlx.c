/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:46:33 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/19 21:51:57 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape)
	{
		printf("the %d key (ESC) has been pressed\n\n", keysym);
		destroy_images(data);
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

void	create_mlx(t_mlx_data *vars, t_map *map)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
		exit_with_error("MLX init ERROR");
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, map->win_width, map->win_height, "so_long");
	if (vars->win_ptr == NULL)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		exit_with_error("MLX window ERROR");
	}
}
