/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:17:28 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/22 20:17:16 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_map(char **map, size_t map_height)
{
	size_t y = 0;

	if (map)
	{
		while (y < map_height)
		{
			free(map[y]);
			y++;
		}
		free(map);
		map = NULL;
	}
}

void exit_with_error(void)
{
	ft_printf("Error\n%s\n", strerror(errno));
	exit(1);
}

void	map_error(char *message, t_map *map)
{
	if (map)
		free_map(map->map_ptr, map->map_height);
	ft_printf("Error\n%s\n", message);
	exit(1);
}

char **copy_map(t_map *map)
{
	char **new_map;
	int y;
	int x;

	new_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
	if (!new_map)
		exit_with_error();
	y = -1;
	while (++y < map->map_height)
	{

		new_map[y] = (char *)malloc((map->map_width + 1) * sizeof(char));
		if (!new_map[y])
		{
			while (y > 0)
				free(new_map[y--]);
			free(new_map);
			exit_with_error();
		}
		x = -1;
		while (++x < map->map_width)
			new_map[y][x] = map->map_ptr[y][x];
	}
	new_map[y] = NULL;
	return (new_map);
}

int open_file(char *file_name)
{
	int fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		exit_with_error();
	if (is_ber_file(file_name) == 0)
		map_error("Map must have .ber extension", NULL);
	return (fd);
}