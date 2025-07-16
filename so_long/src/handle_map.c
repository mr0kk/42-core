/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:17:39 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/16 19:17:39 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_ber_file(char *filename)
{
	size_t len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 5)
		return (0); // .ber and 1 char at least
	if (ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

void reset_gnl(int fd, char *line)
{
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}
void get_map_size(int fd, t_map *map)
{
	char *line;
	size_t line_len;

	map->map_height = 0;
	line = get_next_line(fd);
	if (!line)
		exit_with_error("Map file is empty");
	map->map_width = ft_strlen(line);
	if (line[map->map_width - 1] == '\n')
		map->map_width--;
	while (line && line[0] != 10) /// im not sure if map file ends with endline its ok?
	{
		line_len = ft_strlen(line);
		if (line_len > 0 && line[line_len - 1] == '\n')
			line_len--;
		if (line_len != map->map_width)
		{
			reset_gnl(fd, line);
			exit_with_error("Map must be rectangular");
		}
		map->map_height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

char **create_map(t_map *map, int fd)
{
	size_t y;
	size_t j;
	char **empty_map;

	empty_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
	if (!empty_map)
		exit_with_error("Malloc Error");
	y = 0;
	while (y < map->map_height)
	{
		empty_map[y] = get_next_line(fd);
		if (!empty_map[y])
		{
			j = 0;
			while (j < y)
				free(empty_map[j++]);
			free(empty_map);
			exit_with_error("Error reading map");
		}
		y++;
	}
	empty_map[y] = NULL;
	return (empty_map);
}

void read_map(char *file_name, t_map *map)
{
	int fd;
	int fd2;

	fd = open_file(file_name);
	get_map_size(fd, map);
	close(fd);
	fd2 = open_file(file_name);
	map->map_ptr = create_map(map, fd2);
	close(fd2);
}
