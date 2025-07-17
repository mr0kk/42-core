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
    size_t  block_size;

    if (argc != 2)
    {
        printf("Usage: %s <map_file.ber>\n", argv[0]);
        return (1);
    }
    read_map(argv[1], &map);
    print_map(&map);
    is_map_valid = validate_map(&map);

    if (is_map_valid)
    {
        ft_printf("map is valid\n");
        vars.mlx_ptr = mlx_init();

        if (vars.mlx_ptr == NULL)
            exit_with_error("MLX init ERROR");
        block_size = 64;
        int x = (int)(map.map_width * block_size);
        int y = (int)(map.map_height * block_size);
        vars.win_ptr = mlx_new_window(vars.mlx_ptr, x, y, "so_long");
        if (vars.win_ptr == NULL)
        {
            mlx_destroy_display(vars.mlx_ptr);
            free(vars.mlx_ptr);
            exit_with_error("MLX window ERROR");
        }
        // vars.img.img = mlx_new_image(vars.mlx_ptr, x, y);
        // if (vars.img.img == NULL)
        // {
        //     mlx_destroy_display(vars.mlx_ptr);
        //     free(vars.mlx_ptr);
        //     exit_with_error("MLX image ERROR");
        // }
        // vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
        // if (vars.img.addr == NULL)
        // {
        //     mlx_destroy_image(vars.win_ptr, vars.img.img);
        //     mlx_destroy_display(vars.mlx_ptr);
        //     free(vars.mlx_ptr);
        //     exit_with_error("MLX img addr ERROR");
        // }

        void *img2;
        int height = 64;
        int width = 64;

        void *img1 = mlx_xpm_file_to_image(vars.mlx_ptr, "textures/dino.xpm", &width, &height);;
        mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img1, 0, 0); // vars.img.img
        // img2 = mlx_xpm_file_to_image(vars.mlx_ptr, "textures/dino.xpm", &width, &height);
    
        mlx_key_hook(vars.win_ptr, handle_input, &vars);
    
        // mlx_put_image_to_window(vars.mlx_ptr, vars.win_ptr, img2, 0, 0); // vars.img.img

        mlx_loop(vars.mlx_ptr);

        mlx_destroy_image(vars.mlx_ptr, img2); //  vars.img.img
        mlx_destroy_window(vars.mlx_ptr, vars.win_ptr);
        mlx_destroy_display(vars.mlx_ptr);
        free(vars.mlx_ptr);
    }
    else
        ft_printf("map is NOT valid\n");


    free_map(map.map_ptr, map.map_height);
    printf("collectibles to get: %d\n", map.collectibles);
    printf("start position: (%d, %d)\n", map.player_start.x, map.player_start.y);

    exit(0); // it can also close fd
}