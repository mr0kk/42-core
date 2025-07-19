/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:17:28 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/20 01:14:20 by marvin           ###   ########.fr       */
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

void exit_with_error(char *message)
{
	perror(message);
	exit(1);
}
// to delete later 
void print_map(t_map *map)
{
	size_t y;

	if (!map || !map->map_ptr)
	{
		perror("Error: No map to print");
		return;
	}
	printf("map size: %lu x %lu\n", map->map_width, map->map_height);
	ft_printf("----------------\n");
	y = 0;
	while (y < map->map_height)
	{
		printf("%li | ", y);
		printf("%s", map->map_ptr[y]);
		if (map->map_ptr[y][ft_strlen(map->map_ptr[y]) - 1] != '\n')
			printf("\n");
		y++;
	}
	ft_printf("----------------\n");
}

char **copy_map(t_map *map)
{
	char **new_map;
	int y;
	int x;

	new_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
	if (!new_map)
		exit_with_error("Malloc Error");
	y = -1;
	while (++y < map->map_height)
	{

		new_map[y] = (char *)malloc((map->map_width + 1) * sizeof(char));
		if (!new_map[y])
		{
			while (y > 0)
				free(new_map[y--]);
			free(new_map);
			exit_with_error("Error map copying");
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
		exit_with_error("Error opening a file");
	if (is_ber_file(file_name) == 0)
		exit_with_error("Map must have .ber extension");
	return (fd);
}