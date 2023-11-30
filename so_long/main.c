/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:42:49 by marboccu          #+#    #+#             */
/*   Updated: 2023/11/30 23:02:33 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define GL_SILENCE_DEPRECATION

int ft_window_close(t_data *window)
{
    mlx_destroy_window(window->mlx, window->mlx_win);
    // mlx_destroy_display(window->mlx);
    free(window->mlx);
    exit(0);
    return (0);
}

int main(int ac, char **av)
{
    t_data window;
    if (ac != 2)
        return (1);
    window.map.map = ft_map_init(av[1], &window);
    // map_visualize(window.map);
    window.mlx = mlx_init();
    if (!window.mlx)
        return (1);
    window.size.y = ft_matlen(window.map.map);
    window.size.x = ft_strlen(window.map.map[0]);
    window.map.coins = 0;
    window.moves = 0;
    window.mlx_win = mlx_new_window(window.mlx, window.size.x * IMG_WIDTH, window.size.y * IMG_HEIGHT + BUFFERINO, "so_long");
    if (!window.mlx_win)
        return (free(window.mlx_win), 1);
    ft_render_image(&window);
    ft_put_map(&window, ARROW_DOWN);
    mlx_hook(window.mlx_win, 2, 1L << 0, &ft_key_press, &window);
    mlx_hook(window.mlx_win, 17, 1L << 17, &ft_window_close, &window);
    mlx_loop(window.mlx);
    return (0);
}
