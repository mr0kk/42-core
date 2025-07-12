/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 23:07:17 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/12 23:37:42 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_sqrt(int num)
{
	int res;

	res = 0;
	while (res * res <= num)
		res++;
	if (res * res > num)
		res--;
	return (res);
}

void write_circle(t_img *img, int x_center, int y_center, int r, int color)
{
	int x_start = x_center - r;
	int y_start = y_center - r;
	int x = x_start;
	int y = y_start;

	while (y <= 2 * r + y_start)
	{
		x = x_start;
		while (x <= 2 * r + x_start)
		{
			if (ft_sqrt((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center)) == r)
				my_mlx_pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
	my_mlx_pixel_put(img, x_center, y_center, 0x0000FF00);
}

void circle_shield(t_img *img)
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