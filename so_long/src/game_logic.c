/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:03:04 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/23 00:06:32 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit(t_mlx_data *vars)
{
	if (vars->map.collectibles == 0)
	{
		destroy_images(vars);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free_map(vars->map.map_ptr, vars->map.map_height);
		free(vars->mlx_ptr);
		ft_printf("You won!\n");
		exit(0);
	}
}

void	go_up(t_mlx_data *vars)
{
	int	x;
	int	y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	if (vars->map.map_ptr[y - 1][x] != '1' )
	{
		if (vars->map.map_ptr[y - 1][x] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y - 1][x] == 'C')
			vars->map.collectibles--;
		vars->map.player_start.y--;
		vars->map.moves_counter++;
		vars->map.map_ptr[y - 1][x] = 'P';
		vars->map.map_ptr[y][x] = '0';
		vars->map.map_ptr[vars->map.exit_point.y][vars->map.exit_point.x] = 'E';
		draw_map(vars);
	}
	ft_printf("moves amount: %d\n", vars->map.moves_counter);
}

void	go_down(t_mlx_data *vars)
{
	int	x;
	int	y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	if (vars->map.map_ptr[y + 1][x] != '1')
	{
		if (vars->map.map_ptr[y + 1][x] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y + 1][x] == 'C')
			vars->map.collectibles--;
		vars->map.player_start.y++;
		vars->map.moves_counter++;
		vars->map.map_ptr[y + 1][x] = 'P';
		vars->map.map_ptr[y][x] = '0';
		vars->map.map_ptr[vars->map.exit_point.y][vars->map.exit_point.x] = 'E';
		draw_map(vars);
	}
	ft_printf("moves amount: %d\n", vars->map.moves_counter);
}

void	go_left(t_mlx_data *vars)
{
	int	x;
	int	y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	if (vars->map.map_ptr[y][x - 1] != '1')
	{
		if (vars->map.map_ptr[y][x - 1] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y][x - 1] == 'C')
			vars->map.collectibles--;
		vars->map.player_start.x--;
		vars->map.moves_counter++;
		vars->map.map_ptr[y][x - 1] = 'P';
		vars->map.map_ptr[y][x] = '0';
		vars->map.map_ptr[vars->map.exit_point.y][vars->map.exit_point.x] = 'E';
		draw_map(vars);
	}
	ft_printf("moves amount: %d\n", vars->map.moves_counter);
}

void	go_right(t_mlx_data *vars)
{
	int	x;
	int	y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	if (vars->map.map_ptr[y][x + 1] != '1')
	{
		if (vars->map.map_ptr[y][x + 1] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y][x + 1] == 'C')
			vars->map.collectibles--;
		vars->map.player_start.x++;
		vars->map.moves_counter++;
		vars->map.map_ptr[y][x + 1] = 'P';
		vars->map.map_ptr[y][x] = '0';
		vars->map.map_ptr[vars->map.exit_point.y][vars->map.exit_point.x] = 'E';
		draw_map(vars);
	}
	ft_printf("moves amount: %d\n", vars->map.moves_counter);
}
