/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 22:03:04 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/21 23:27:42 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_exit(t_mlx_data *vars)
{
	printf("collectibles when E: %d\n", vars->map.collectibles);
	if (vars->map.collectibles == 0)
	{
		destroy_images(vars);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free_map(vars->map.map_ptr, vars->map.map_height);
		free(vars->mlx_ptr);
		ft_printf("you win!\n");
		ft_printf("you did %d moves\n", vars->map.moves_counter);
		exit(0);
	}
}

void	go_up(t_mlx_data *vars)
{
	int	x;
	int	y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	ft_printf("going up!\n");
	if (vars->map.map_ptr[y - 1][x] != '1' )
	{
		if (vars->map.map_ptr[y - 1][x] == 'C')
			vars->map.collectibles--;
		if (vars->map.map_ptr[y - 1][x] != 'E')
		{
			vars->map.player_start.y--;
			vars->map.moves_counter++;
			vars->map.map_ptr[y - 1][x] = 'P';
			vars->map.map_ptr[y][x] = '0';
			draw_map(vars);
		}
	}
}

void go_down(t_mlx_data *vars)
{
	int x;
	int y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	ft_printf("going down!\n");
	if (vars->map.map_ptr[y + 1][x] != '1')
	{
		if (vars->map.map_ptr[y + 1][x] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y + 1][x] == 'C')
			vars->map.collectibles--;
		if (vars->map.map_ptr[y + 1][x] != 'E')
		{
			vars->map.player_start.y++;
			vars->map.moves_counter++;
			vars->map.map_ptr[y + 1][x] = 'P';
			vars->map.map_ptr[y][x] = '0';
			draw_map(vars);
		}
	}
}

void go_left(t_mlx_data *vars)
{
	int x;
	int y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	ft_printf("going left!\n");
	if (vars->map.map_ptr[y][x - 1] != '1')
	{
		if (vars->map.map_ptr[y][x - 1] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y][x - 1] == 'C')
			vars->map.collectibles--;
		if (vars->map.map_ptr[y][x - 1] != 'E')
		{
			vars->map.player_start.x--;
			vars->map.moves_counter++;
			vars->map.map_ptr[y][x - 1] = 'P';
			vars->map.map_ptr[y][x] = '0';
			draw_map(vars);
		}
	}
}

void go_right(t_mlx_data *vars)
{
	int x;
	int y;

	x = vars->map.player_start.x;
	y = vars->map.player_start.y;
	ft_printf("going left!\n");
	if (vars->map.map_ptr[y][x + 1] != '1')
	{
		if (vars->map.map_ptr[y][x + 1] == 'E')
			handle_exit(vars);
		if (vars->map.map_ptr[y][x + 1] == 'C')
			vars->map.collectibles--;
		if (vars->map.map_ptr[y][x + 1] != 'E')
		{
			vars->map.player_start.x++;
			vars->map.moves_counter++;
			vars->map.map_ptr[y][x + 1] = 'P';
			vars->map.map_ptr[y][x] = '0';
		}
		draw_map(vars);
	}
}
