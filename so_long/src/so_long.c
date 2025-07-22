/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:17:35 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/16 19:17:35 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx_data *vars, void *texture, int x, int y)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, texture,
		x * vars->map.block_size, y * vars->map.block_size);
}

void	set_point(t_point *item, size_t w, size_t h, int *counter)
{
	item->x = w;
	item->y = h;
	*counter += 1;
}

int	main(int argc, char *argv[])
{
	t_mlx_data	vars;
	int			is_map_valid;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file.ber>\n", argv[0]);
		exit(1);
	}
	read_map(argv[1], &vars.map);
	is_map_valid = validate_map(&vars.map);
	if (is_map_valid)
		map_rendering(&vars);
	free_map(vars.map.map_ptr, vars.map.map_height);
	exit(0);
}
