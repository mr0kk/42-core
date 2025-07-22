/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:04:30 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/23 00:06:00 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	image_check(t_mlx_data *vars)
{
	if (!vars->grass)
		return (1);
	if (!vars->wall)
		return (1);
	if (!vars->dino)
		return (1);
	if (!vars->exit)
		return (1);
	if (!vars->duck)
		return (1);
	return (0);
}

void	create_images(t_mlx_data *vars)
{
	int	h;
	int	w;

	vars->grass = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/grass.xpm", &w, &h);
	vars->wall = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/wall.xpm", &w, &h);
	vars->dino = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/dino.xpm", &w, &h);
	vars->exit = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/exit.xpm", &w, &h);
	vars->duck = mlx_xpm_file_to_image(vars->mlx_ptr,
			"textures/duck.xpm", &w, &h);
	if (image_check(vars))
	{
		free_map(vars->map.map_ptr, vars->map.map_height);
		exit_with_error();
	}
	if (w == h)
		vars->map.block_size = w;
	else
		vars->map.block_size = 64;
	vars->map.win_height = (int)(vars->map.block_size * vars->map.map_height);
	vars->map.win_width = (int)(vars->map.block_size * vars->map.map_width);
}

void	images_to_window(t_mlx_data *vars, int x, int y)
{
	if (vars->map.map_ptr[y][x] == '1')
		put_image(vars, vars->wall, x, y);
	else if (vars->map.map_ptr[y][x] == 'C')
		put_image(vars, vars->duck, x, y);
	else if (vars->map.map_ptr[y][x] == '0')
		put_image(vars, vars->grass, x, y);
	else if (vars->map.map_ptr[y][x] == 'P')
		put_image(vars, vars->dino, x, y);
	else if (vars->map.map_ptr[y][x] == 'E')
		put_image(vars, vars->exit, x, y);
	else
		map_error("Unknown component", &vars->map);
	put_image(vars, vars->exit, vars->map.exit_point.x,
		vars->map.exit_point.y);
	put_image(vars, vars->dino, vars->map.player_start.x,
		vars->map.player_start.y);
}

void	draw_map(t_mlx_data *vars)
{
	int	x;
	int	y;
	int	h;
	int	w;

	y = -1;
	w = vars->map.map_width;
	h = vars->map.map_height;
	while (++y < h)
	{
		x = -1;
		while (++x < w)
			images_to_window(vars, x, y);
	}
}

void	map_rendering(t_mlx_data *vars)
{
	vars->map.moves_counter = 0;
	create_mlx(vars);
	draw_map(vars);
	mlx_hook(vars->win_ptr, 17, 0, handle_close, vars);
	mlx_key_hook(vars->win_ptr, handle_input, vars);
	mlx_loop(vars->mlx_ptr);
}
