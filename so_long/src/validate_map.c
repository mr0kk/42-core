#include "so_long.h"

// char    **copy_map(t_map *map)
// {
//     char    **new_map;
//     int     y;
//     int     x;

//     new_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
//     if (!new_map)
//         exit_with_error("Malloc Error");
//     y = 0;
//     while (y < map->map_height)
//     {
//         x = 0;
//         new_map[y] = (char *)malloc((map->map_width + 1) * sizeof(char));
//         if (!new_map[y])
//         {
//             while (y > 0)
//                 free(new_map[y--]);
//             free(new_map);
//             exit_with_error("Error map copying");
//         }
//         while (x < map->map_width)
//             new_map[y][x++] = map->map_ptr[y][x];
//         y++;
//     }
//     return (new_map);
// }

// int is_accessible(t_map *map)
// {
//     // char    **map_copy;

//     // map_copy = copy_map(map);
//     // print_map(map_copy);
//     // free_map()
//     return (1);
// }

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
            {
                p_counter++;
                map->player_start.x = j;
                map->player_start.y = i;
            }
            if (map->map_ptr[i][j++] == 'C')
                map->collectibles++;
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
    if (enclosed_in_walls(map) && fields_counter(map)) // && is_accessible(map)
        return (1);
    else
        return (0);
}