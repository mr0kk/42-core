/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmrok <rmrok@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:17:35 by rmrok             #+#    #+#             */
/*   Updated: 2025/07/16 19:17:35 by rmrok            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    t_map map;
    
    int is_map_valid;

    if (argc != 2)
    {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }

    read_map(argv[1], &map);
    print_map(&map);
    is_map_valid = validate_map(&map);
    if (is_map_valid)
        ft_printf("map is valid\n");
    else
        ft_printf("map is NOT valid\n");


    free_map(map.map_ptr, map.map_height);
    printf("collectibles to get: %d\n", map.collectibles);
    printf("start position: (%d, %d)\n", map.player_start.x, map.player_start.y);

    exit(0); // it can also close fd
}