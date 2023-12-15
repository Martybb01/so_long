/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 15:31:51 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/10 00:53:13 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_player_go(t_data *matrix, t_point *temp_pos)
{
	if (matrix->map.map[temp_pos->y][temp_pos->x] == '1')
		return (1);
	else if (matrix->map.map[temp_pos->y][temp_pos->x] == 'C')
		matrix->map.coins++;
	else if (matrix->map.map[temp_pos->y][temp_pos->x] == 'E')
	{
		if (matrix->map.coins == matrix->coins_collected)
		{
			ft_printf("YOU WIN!\n");
			ft_window_close(matrix);
		}
		return (1);
	}
	return (0);
}

static void	ft_put_on_screen(t_data *matrix, int keycode)
{
	char	*str;
	char	*str2;

	ft_put_map(matrix, keycode);
	str = ft_itoa(matrix->map.coins);
	str2 = ft_strjoin("coins: ", str);
	mlx_string_put(matrix->mlx, matrix->mlx_win, 10, 10, 0x000000, str2);
	free(str);
	free(str2);
	str = ft_itoa(matrix->moves);
	str2 = ft_strjoin("moves: ", str);
	mlx_string_put(matrix->mlx, matrix->mlx_win, 10, 25, 0x000000, str2);
	free(str);
	free(str2);
}

int	ft_key_press(int keycode, t_data *matrix)
{
	t_point	temp_pos;

	temp_pos = matrix->player_pos;
	if (keycode == ESC)
		ft_window_close(matrix);
	else if (keycode == 'w' || keycode == ARROW_UP)
		temp_pos.y -= 1;
	else if (keycode == 's' || keycode == ARROW_DOWN)
		temp_pos.y += 1;
	else if (keycode == 'a' || keycode == ARROW_LEFT)
		temp_pos.x -= 1;
	else if (keycode == 'd' || keycode == ARROW_RIGHT)
		temp_pos.x += 1;
	else
		return (0);
	if (!ft_player_go(matrix, &temp_pos))
	{
		matrix->moves++;
		matrix->map.map[temp_pos.y][temp_pos.x] = 'P';
		matrix->map.map[matrix->player_pos.y][matrix->player_pos.x] = '0';
	}
	matrix->player_pos = temp_pos;
	ft_put_on_screen(matrix, keycode);
	return (0);
}
