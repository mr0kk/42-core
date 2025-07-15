#include "so_long.h"

void print_map2(char **map, size_t height, size_t width)
{
    size_t y;

    if (!map)
    {
        perror("Error: No map to print");
        return;
    }
    printf("map size: %lu x %lu\n", width, height);
    ft_printf("----------------\n");
    y = 0;
    while (y < height)
    {
        printf("%li | ", y);
        if (map[y]) // Additional safety check
        {
            printf("%s", map[y]);
            if (map[y][ft_strlen(map[y]) - 1] != '\n')
                printf("\n");
        }
        else
        {
            printf("(null row)\n");
        }
        y++;
    }
    ft_printf("----------------\n");
}

char    **copy_map(t_map *map)
{
    char    **new_map;
    int     y;
    int     x;

    new_map = (char **)malloc((map->map_height + 1) * sizeof(char *));
    if (!new_map)
        exit_with_error("Malloc Error");
    y = 0;
    while (y < map->map_height)
    {
        
        new_map[y] = (char *)malloc((map->map_width + 1) * sizeof(char));
        if (!new_map[y])
        {
            while (y > 0)
                free(new_map[y--]);
            free(new_map);
            exit_with_error("Error map copying");
        }
        y++;
    }

    y = 0;
    while (y < map->map_height)
    {
        x = 0;
        while (x < map->map_width)
        {
            new_map[y][x] = map->map_ptr[y][x];
            x++;
        }
        y++;
    }
    return (new_map);
}

int is_accessible(t_map *map)
{
    char    **map_copy;

    map_copy = copy_map(map);
    print_map2(map_copy, map->map_height, map->map_width);
    free_map(map_copy, map->map_height);
    return (1);
}

int fields_counter(t_map *map)
{
    size_t i;
    size_t j;
    int p_counter;
    int e_counter;

    p_counter = 0;
    e_counter = 0;
    map->collectibles = 0;
    i = -1;
    while (++i < map->map_height - 1)
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
    }
    return ((p_counter == 1) && e_counter == 1 && map->collectibles > 0);
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
    if (enclosed_in_walls(map) && fields_counter(map) && is_accessible(map))
        return (1);
    else
        return (0);
}