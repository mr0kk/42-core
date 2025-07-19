/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:00:10 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/19 22:06:39 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
// #include <errno.h>
// # include <mlx.h>
#define WIN_HEIGHT 500
#define WIN_WIDTH 500

/**
 * 	this struct contains information about an image
 */
typedef struct s_img
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

/**
 *  this struct contains all the mlx stuff
 * 	and the image where we buffer pixels
 */
typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	void	*grass;
	void	*wall;
	void	*dino;
	void	*duck;
	void	*exit;
	t_img img;
} t_mlx_data;

typedef struct s_point
{
	int x;
	int y;
} t_point;

typedef struct s_map
{
	char **map_ptr;
	size_t map_width;
	size_t map_height;
	int collectibles;
	int exit_counter;
	t_point player_start;
	char *wall_xpm;
	char *exit_xpm;
	char *player_xpm;
	char *coll_xpm;
	char *backgrd_xpm;
	size_t block_size;
	int	win_height;
	int win_width;
} t_map;

void print_map(t_map *map); // to delete later
void my_mlx_pixel_put(t_img *data, int x, int y, int color);
void write_circle(t_img *img, int x_center, int y_center,
				  int r, int color);
void circle_shield(t_img *img);
int ft_sqrt(int num);
int is_ber_file(char *filename);
int open_file(char *file_name);
void read_map(char *file_name, t_map *map);
void free_map(t_map *map, size_t map_height);
int validate_map(t_map *map);
void exit_with_error(char *message);
char **copy_map(t_map *map);
int handle_input(int keysym, t_mlx_data *data);
void my_mlx_pixel_put(t_img *data, int x, int y, int color);
void map_rendering(t_mlx_data *vars, t_map *map);
void set_map_values(t_map *map);
void create_mlx(t_mlx_data *vars, t_map *map);
void	destroy_images(t_mlx_data *vars);

#endif