/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:17:31 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/16 19:17:31 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    flood_fill(char **map, size_t x, size_t y, t_map *data)
{
    char    current;

    if (y < 0 || x < 0 || y >= data->map_height || x >= data->map_width)
        return ;
    if (map[y][x] == '1' || map[y][x] == 'X')
        return ;
    current = map[y][x];
    map[y][x] = 'X';
    if (current == 'C')
        data->collectibles--;
    if (current == 'E')
        data->exit_counter--;
    
    flood_fill(map, x - 1, y, data);
    flood_fill(map, x + 1, y, data);
    flood_fill(map, x, y - 1, data);
    flood_fill(map, x, y + 1, data);
}

int is_accessible(t_map *map)
{
    char    **map_copy;
    int     collectible_amount;

    map_copy = copy_map(map);
    collectible_amount = map->collectibles;
    flood_fill(map_copy, map->player_start.x, map->player_start.y, map);
    if (map->collectibles != 0 || map->exit_counter != 0)
    {
        free_map(map_copy, map->map_height);
        return (0);
    }
    map->collectibles = collectible_amount;
    free_map(map_copy, map->map_height);
    return (1);
}

int fields_counter(t_map *map)
{
    size_t i;
    size_t j;
    int p_counter;

    p_counter = 0;
    i = -1;
    while (++i < map->map_height - 1)
    {
        j = 1;
        while (j < map->map_width - 1)
        {
            if (map->map_ptr[i][j] == 'E')
                map->exit_counter++;
            if (map->map_ptr[i][j] == 'P')
            {
                p_counter++;
                map->player_start.x = j;
                map->player_start.y = i;
            }
            if (map->map_ptr[i][j++] == 'C')
                map->collectibles++;
        }
    }
    return ((p_counter == 1) && map->exit_counter == 1 && map->collectibles > 0);
}

int enclosed_in_walls(t_map *map)
{
    size_t i;

    i = 0;
    while (i < map->map_width)
        if (map->map_ptr[0][i++] != '1')
            return (0);
    i = 0;
    while (i < map->map_width)
        if (map->map_ptr[map->map_height - 1][i++] != '1')
            return (0);
    i = 0;
    while (i < map->map_height)
        if (map->map_ptr[i++][0] != '1')
            return (0);
    i = 0;
    while (i < map->map_height)
        if (map->map_ptr[i++][map->map_width - 1] != '1')
            return (0);
    return (1);
}

int validate_map(t_map *map)
{
    map->exit_counter = 0;
    map->collectibles = 0;
    return (enclosed_in_walls(map) && fields_counter(map) && is_accessible(map));
}