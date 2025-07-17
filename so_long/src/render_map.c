/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 01:04:30 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/18 01:58:22 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_map(t_map *map)
{
	map->wall_img = "textures/wall.xpm";
	map->player_img = "textures/dino.xpm";
	map->coll_img = "textures/duck.xpm";
	map->exit_img = "textures/exit.xpm";
	map->backgrd_img = "textures/grass.xpm";
	map->block_size = 64;
}

void	put_block(int x, int y, t_map *map, t_mlx_data *vars, char *img_name)
{
	void	*img;
	int height;
	int width;

	height = (int)map->block_size;
	width = (int)map->block_size;
	img = mlx_xpm_file_to_image(vars->mlx_ptr, img_name, &width, &height);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, img, x, y);
}

void	draw_map(t_map *map, t_mlx_data *vars)
{
	int	x;
	int	y;
	int h;
	int w;

	y = 0;
	w = map->map_width;
	h = map->map_height;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (map->map_ptr[y][x] == '1')
				put_block(x * map->block_size, y * map->block_size, map, vars, map->wall_img);
			if (map->map_ptr[y][x] == 'C')
				put_block(x * map->block_size, y * map->block_size, map, vars, map->coll_img);
			if (map->map_ptr[y][x] == 'P')
				put_block(x * map->block_size, y * map->block_size, map, vars, map->player_img);
			if (map->map_ptr[y][x] == '0')
				put_block(x * map->block_size, y * map->block_size, map, vars, map->backgrd_img);
			if (map->map_ptr[y][x] == 'E')
				put_block(x * map->block_size, y * map->block_size, map, vars, map->exit_img);
			x++;
		}
		y++;
	}
}

void	map_rendering(t_mlx_data *vars, t_map *map)
{
	void	*img;
	int		height;
	int		width;
	
	set_map(map);
	height = width = (int)map->block_size;
	
	draw_map(map, vars);
	
	mlx_key_hook(vars->win_ptr, handle_input, vars);
	mlx_loop(vars->mlx_ptr);

	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	free(img);

}