/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:42:49 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/01 15:20:49 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define GL_SILENCE_DEPRECATION

static int ft_init_vars(t_data *window)
{
    window->map.coins = 0;
    window->coins_collected = 0;
    window->moves = 0;
    window->exit_count = 0;
    window->player_count = 0;
    return (0);
}

int main(int ac, char **av)
{
    t_data window;
    if (ac != 2)
        return (1);
    ft_init_vars(&window);
    window.map.map = ft_map_init(av[1], &window);
    window.size.y = ft_matlen(window.map.map);
    window.size.x = ft_strlen(window.map.map[0]);
    ft_checkerrors(&window);
    window.mlx = mlx_init();
    if (!window.mlx)
        return (1);
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
