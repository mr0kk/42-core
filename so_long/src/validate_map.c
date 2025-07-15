#include "so_long.h"

int fields_counter(t_map *map)
{
    int i;
    int j;
    int p_counter;
    int e_counter;

    p_counter = 0;
    e_counter = 0;
    map->collectibles = 0;
    i = 1;
    while (i < map->map_height - 1)
    {
        j = 1;
        while (j < map->map_width - 1)
        {
            if (map->map_ptr[i][j] == 'E')
                e_counter++;
            if (map->map_ptr[i][j] == 'P')
                p_counter++;
            if (map->map_ptr[i][j] == 'C')
                map->collectibles++;
            j++;
        }
        i++;
    }
    return ((p_counter == 1) && e_counter == 1 && map->collectibles > 0);
}

int enclosed_in_walls(t_map *map)
{
    int i;

    i = 0;
     while (i < map->map_width)
        if (map->map_ptr[0][i++] !=  '1')
            return (0);
    i = 0;
    while (i < map->map_width)
        if (map->map_ptr[map->map_height - 1][i++] !=  '1')
            return (0);
    i = 0;
    while (i < map->map_height)
        if (map->map_ptr[i++][0] !=  '1')
            return (0);
    i = 0;
    while (i < map->map_height)
        if (map->map_ptr[i++][map->map_width - 1] !=  '1')
            return (0);
    return (1);
}

int validate_map(t_map *map)
{
    if (enclosed_in_walls(map) && fields_counter(map) && is_accessible(map))
        return (1);
    else
        return (0);
}