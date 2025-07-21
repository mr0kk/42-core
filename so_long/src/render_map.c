/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:04:30 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/21 22:28:15 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	create_images(t_mlx_data *vars)
{
	int h;
	int w;

	vars->grass = mlx_xpm_file_to_image(vars->mlx_ptr, "textures/grass.xpm", &w, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx_ptr, "textures/wall.xpm", &w, &h);
	vars->dino = mlx_xpm_file_to_image(vars->mlx_ptr, "textures/dino.xpm", &w, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx_ptr, "textures/exit.xpm", &w, &h);
	vars->duck = mlx_xpm_file_to_image(vars->mlx_ptr, "textures/duck.xpm", &w, &h);
	if (!vars->grass || !vars->wall || !vars->dino || !vars->exit || !vars->duck)
	{
		destroy_images(vars);
		free_map(vars->map.map_ptr, vars->map.map_height);
		exit_with_error("Error: Failed to load  image\n");
	}
	if (w == h)
		vars->map.block_size = w;
	else
		vars->map.block_size = 64;
	vars->map.win_height = (int)(vars->map.block_size * vars->map.map_height);
	vars->map.win_width = (int)(vars->map.block_size * vars->map.map_width);
}

void	draw_map(t_mlx_data *vars)
{
	int	x;
	int	y;
	int h;
	int w;

	y = 0;
	w = vars->map.map_width;
	h = vars->map.map_height;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (vars->map.map_ptr[y][x] == '1')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->wall, x * vars->map.block_size, y * vars->map.block_size);
			else if (vars->map.map_ptr[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->duck, x * vars->map.block_size, y * vars->map.block_size);
			else if (vars->map.map_ptr[y][x] == '0')
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->grass, x * vars->map.block_size, y * vars->map.block_size);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->dino, vars->map.player_start.x * vars->map.block_size, vars->map.player_start.y * vars->map.block_size);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->exit, vars->map.exit_point.x * vars->map.block_size, vars->map.exit_point.y * vars->map.block_size);
}

void	map_rendering(t_mlx_data *vars)
{
	vars->map.moves_counter = 0;
	printf("current move amount: %d\n", vars->map.moves_counter);
	create_mlx(vars);
	draw_map(vars);
	
	mlx_key_hook(vars->win_ptr, handle_input, vars);
	mlx_loop(vars->mlx_ptr);

	// this is not executing 
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);

}