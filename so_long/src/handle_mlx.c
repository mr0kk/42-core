/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:46:33 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/21 23:14:28 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void destroy_images(t_mlx_data *vars)
{
	mlx_destroy_image(vars->mlx_ptr, vars->grass);
	mlx_destroy_image(vars->mlx_ptr, vars->dino);
	mlx_destroy_image(vars->mlx_ptr, vars->wall);
	mlx_destroy_image(vars->mlx_ptr, vars->duck);
	mlx_destroy_image(vars->mlx_ptr, vars->exit);
}

int handle_input(int keysym, t_mlx_data *data)
{
	printf("collectibles to get: %d\n", data->map.collectibles);
	if (keysym == XK_w)
		go_up(data);
	else if (keysym == XK_s)
		go_down(data);
	else if (keysym == XK_a)
		go_left(data);
	else if (keysym == XK_d)
		go_right(data);
	else if (keysym == XK_Escape)
	{
		printf("the %d key (ESC) has been pressed\n\n", keysym);
		destroy_images(data);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free_map(data->map.map_ptr, data->map.map_height);
		free(data->mlx_ptr);
		exit(0);
	}
	printf("current move amount: %d\n", data->map.moves_counter);
	printf("the %d key has been pressed\n\n", keysym);
}

void create_mlx(t_mlx_data *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
		exit_with_error("MLX init ERROR");
	create_images(vars);
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->map.win_width, vars->map.win_height, "so_long");
	if (vars->win_ptr == NULL)
	{
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		free_map(vars->map.map_ptr, vars->map.map_height);
		exit_with_error("MLX window ERROR");
	}
}
