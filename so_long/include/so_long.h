/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:00:10 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/21 21:21:26 by rmrok            ###   ########.fr       */
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
	int p_counter;
	t_point player_start;
	t_point exit_point;
	size_t block_size;
	int win_height;
	int win_width;
} t_map;

typedef struct s_mlx_data
{
	void *mlx_ptr;
	void *win_ptr;
	t_map map;
	void *grass;
	void *wall;
	void *dino;
	void *duck;
	void *exit;
} t_mlx_data;

void print_map(t_map *map); // to delete later
int ft_sqrt(int num);
int is_ber_file(char *filename);
int open_file(char *file_name);
void read_map(char *file_name, t_map *map);
void free_map(char **map, size_t map_height);
int validate_map(t_map *map);
void exit_with_error(char *message);
char **copy_map(t_map *map);
int handle_input(int keysym, t_mlx_data *data);
void map_rendering(t_mlx_data *vars);
void create_mlx(t_mlx_data *vars);
void create_images(t_mlx_data *vars);
void destroy_images(t_mlx_data *vars);

#endif