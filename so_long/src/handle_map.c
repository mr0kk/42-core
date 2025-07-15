#include "so_long.h"

void free_map(t_map *map)
{
    int y = 0;

    if (map->map_ptr)
    {
        while (y < map->map_height)
        {
            free(map->map_ptr[y]);
            y++;
        }
        free(map->map_ptr);
        map->map_ptr = NULL;
    }
}

void exit_with_error(char *message)
{
    perror(message);
    exit(1);
}

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
}

char **create_map(t_map *map, int fd)
{
    int y;
    int j;
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

void print_map(t_map *map)
{
    int y;

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
        printf("%i | ", y);
        printf("%s", map->map_ptr[y]);
        if (map->map_ptr[y][ft_strlen(map->map_ptr[y]) - 1] != '\n')
            printf("\n");
        y++;
    }
    ft_printf("----------------\n");
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

// int main(int argc, char *argv[])
// {
//     t_map map;

//     if (argc != 2)
//     {
//         printf("Usage: %s <map_file.ber>\n", argv[0]);
//         return (1);
//     }

//     read_map(argv[1], &map);
//     printf("map width in main: %lu\n", map.map_width);
//     printf("map height in main: %lu\n\n", map.map_height);

//     print_map(&map);

//     free_map(&map);
//     exit(0); // it can also close fd
// }