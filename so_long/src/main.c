/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:02:52 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/12 17:51:23 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#define WIN_HEIGHT 600
#define WIN_WIDTH 600

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
};


int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_window;

	//opening connection
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	// creating window
	mlx_window = mlx_new_window(mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "so_long prep");
	if (!mlx_window)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return(1);
	}
	
	mlx_loop(mlx_ptr); // loop in which process keep listening for events
	

	
	// clean up section 
	mlx_destroy_window(mlx_ptr, mlx_window);
	mlx_destroy_display(mlx_ptr); // frees display before exit
	free(mlx_ptr);
	
}