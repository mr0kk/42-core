/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:02:52 by rmrok             #+#    #+#             */
/*   Updated: 2025/04/10 15:02:49 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int main(void)
{
	void	*mlx;
	t_data	img;
	// void	*mlx_win;
	
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 500, 500);
	// mlx_win = mlx_new_window(mlx, 500, 500, "Hello World!");
	// mlx_loop(mlx);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
}