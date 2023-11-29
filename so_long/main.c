#include "so_long.h"
#define GL_SILENCE_DEPRECATION

int ft_key_press(int keycode, t_data *matrix)
{
    char *str;
    char *str2;
    if (keycode == ESC)
        exit(1);
    else if (keycode == 'w' || keycode == ARROW_UP)
    {
        if (matrix->player_y - 1 >= 0 && matrix->map.map[matrix->player_y - 1][matrix->player_x] != '1' && matrix->map.map[matrix->player_y][matrix->player_x + 1] != 'E')
        {
            matrix->moves += 1;
            if (matrix->map.map[matrix->player_y - 1][matrix->player_x] == 'C')
                matrix->map.coins += 1;
            if (matrix->map.map[matrix->player_y - 1][matrix->player_x] == 'E' && matrix->map.coins == matrix->coins_collected)
            {
                // printf("ciao lol"); non funziona
                exit(0);
            }
            else if (matrix->map.map[matrix->player_y - 1][matrix->player_x] == 'E' && matrix->map.coins != matrix->coins_collected)
            {
                matrix->map.map[matrix->player_y][matrix->player_x] = 'P';
                matrix->map.map[matrix->player_y - 1][matrix->player_x] = 'E';
            }
            matrix->map.map[matrix->player_y][matrix->player_x] = '0';
            matrix->map.map[matrix->player_y - 1][matrix->player_x] = 'P';
            ft_put_map(matrix, keycode);
        }
    }
    else if (keycode == 's' || keycode == ARROW_DOWN)
    {
        if (matrix->player_y + 1 >= 0 && matrix->map.map[matrix->player_y + 1][matrix->player_x] != '1' && matrix->map.map[matrix->player_y][matrix->player_x + 1] != 'E')
        {
            matrix->moves += 1;
            if (matrix->map.map[matrix->player_y + 1][matrix->player_x] == 'C')
                matrix->map.coins += 1;
            if (matrix->map.map[matrix->player_y + 1][matrix->player_x] == 'E' && matrix->map.coins == matrix->coins_collected)
                exit(0);
            else if (matrix->map.map[matrix->player_y + 1][matrix->player_x] == 'E' && matrix->map.coins != matrix->coins_collected)
            {
                matrix->map.map[matrix->player_y][matrix->player_x] = 'P';
                matrix->map.map[matrix->player_y + 1][matrix->player_x] = 'E';
            }
            matrix->map.map[matrix->player_y][matrix->player_x] = '0';
            matrix->map.map[matrix->player_y + 1][matrix->player_x] = 'P';
            ft_put_map(matrix, keycode);
        }
    }
    else if (keycode == 'a' || keycode == ARROW_LEFT)
    {
        if (matrix->player_x - 1 >= 0 && matrix->map.map[matrix->player_y][matrix->player_x - 1] != '1' && matrix->map.map[matrix->player_y][matrix->player_x + 1] != 'E')
        {
            matrix->moves += 1;
            if (matrix->map.map[matrix->player_y][matrix->player_x - 1] == 'C')
                matrix->map.coins += 1;
            if (matrix->map.map[matrix->player_y][matrix->player_x - 1] == 'E' && matrix->map.coins == matrix->coins_collected)
            {
                exit(0);
            }
            else if (matrix->map.map[matrix->player_y][matrix->player_x - 1] == 'E' && matrix->map.coins != matrix->coins_collected)
            {
                printf("ciao");
                matrix->map.map[matrix->player_y][matrix->player_x] = 'P';
                matrix->map.map[matrix->player_y][matrix->player_x - 1] = 'E';
            }
            matrix->map.map[matrix->player_y][matrix->player_x] = '0';
            matrix->map.map[matrix->player_y][matrix->player_x - 1] = 'P';
            ft_put_map(matrix, keycode);
        }
    }
    else if (keycode == 'd' || keycode == ARROW_RIGHT)
    {
        if (matrix->player_x + 1 >= 0 && matrix->map.map[matrix->player_y][matrix->player_x + 1] != '1' && matrix->map.map[matrix->player_y][matrix->player_x + 1] != 'E')
        {
            matrix->moves += 1;
            if (matrix->map.map[matrix->player_y][matrix->player_x + 1] == 'C')
                matrix->map.coins += 1;
            if (matrix->map.map[matrix->player_y][matrix->player_x + 1] == 'E' && matrix->map.coins == matrix->coins_collected)
            {
                exit(0);
            }
            else if (matrix->map.map[matrix->player_y][matrix->player_x + 1] == 'E' && matrix->map.coins != matrix->coins_collected)
            {
                matrix->map.map[matrix->player_y][matrix->player_x] = 'P';
                matrix->map.map[matrix->player_y][matrix->player_x + 1] = 'E';
            }
            matrix->map.map[matrix->player_y][matrix->player_x] = '0';
            matrix->map.map[matrix->player_y][matrix->player_x + 1] = 'P';
            ft_put_map(matrix, keycode);
        }
    }
    str = ft_strjoin("coins: ", ft_itoa(matrix->map.coins));
    mlx_string_put(matrix->mlx, matrix->mlx_win, 10, 10, 0x000000, str);
    str2 = ft_strjoin("moves: ", ft_itoa(matrix->moves));
    mlx_string_put(matrix->mlx, matrix->mlx_win, 10, 25, 0x000000, str2);

    // if (matrix->map.coins == matrix->coins_collected && matrix->map.map[matrix->player_y][matrix->player_x] == 'E')
    //     mlx_string_put(matrix->mlx, matrix->mlx_win, 10, 10, 0x000000, "You win! Esc to exit");
    return (0);
}

int ft_window_close(t_data *window)
{
    mlx_destroy_window(window->mlx, window->mlx_win);
    mlx_destroy_display(window->mlx);
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
    window.size_y = ft_matlen(window.map.map);
    window.size_x = ft_strlen(window.map.map[0]);
    window.map.coins = 0;
    window.moves = 0;
    window.mlx_win = mlx_new_window(window.mlx, window.size_x * IMG_WIDTH, window.size_y * IMG_HEIGHT + BUFFERINO, "so_long");
    if (!window.mlx_win)
        return (free(window.mlx_win), 1);
    ft_render_image(&window);
    ft_put_map(&window, ARROW_DOWN);
    mlx_hook(window.mlx_win, 2, 1L << 0, &ft_key_press, &window);
    mlx_hook(window.mlx_win, 17, 1L << 17, &ft_window_close, &window);
    mlx_loop(window.mlx);
    return (0);
}
