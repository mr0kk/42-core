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
    t_mlx_data vars;
    int is_map_valid;

    if (argc != 2)
    {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
        exit(1);
    }
    read_map(argv[1], &vars.map);
    print_map(&vars.map);
    is_map_valid = validate_map(&vars.map);

    if (is_map_valid)
    {
        ft_printf("map is valid\n");
        printf("collectibles to get: %d\n", vars.map.collectibles);
        printf("player start position: (%u, %u)\n", vars.map.player_start.x, vars.map.player_start.y);
        printf("exit start position: (%u, %u)\n", vars.map.exit_point.x, vars.map.exit_point.y);
        map_rendering(&vars);
    }
    else
        ft_printf("map is NOT valid\n");

    printf("here after program\n");
    free_map(vars.map.map_ptr, vars.map.map_height);
    exit(0); // it can also close fd
}