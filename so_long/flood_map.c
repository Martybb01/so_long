/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:31:56 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/04 23:51:48 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// dfs algo to check if the exit is accessible from the starting position

t_point ft_find_player(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){-1, -1});
}

void ft_dfs(char **map, t_point size, t_point curr, t_data *special)
{
	if (curr.x < 0 || curr.x + 1 >= size.x || curr.y < 0 || curr.y + 1 >= size.y || map[curr.y][curr.x] == '1')
		return;
	if (map[curr.y][curr.x] == 'E')
		special->exit_count++;
	else if (map[curr.y][curr.x] == 'C')
		special->map.coins++;

	map[curr.y][curr.x] = '1';
	ft_dfs(map, size, (t_point){curr.x - 1, curr.y}, special);
	ft_dfs(map, size, (t_point){curr.x, curr.y - 1}, special);
	ft_dfs(map, size, (t_point){curr.x + 1, curr.y}, special);
	ft_dfs(map, size, (t_point){curr.x, curr.y + 1}, special);
}

char **ft_copy_matrix(char **matrix, int rows, int cols)
{

	char **copy;
	int i;

	copy = malloc(sizeof(char *) * rows);
	i = 0;
	while (i < rows)
	{
		copy[i] = malloc(sizeof(char) * cols);
		ft_memcpy(copy[i], matrix[i], sizeof(char) * cols);
		i++;
	}
	return (copy);
}

void ft_free_matrix(char **matrix, int rows)
{
	int i;

	i = 0;
	while (i < rows)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int ft_is_reachable(t_data *matrix)
{
	t_point curr;
	t_point size;
	t_data special;
	char **matrix_copy;

	curr = ft_find_player(matrix->map.map);

	size.x = matrix->size.x;
	size.y = matrix->size.y;

	special.map.coins = 0;
	special.exit_count = 0;

	matrix_copy = ft_copy_matrix(matrix->map.map, size.y, size.x);
	ft_dfs(matrix_copy, size, curr, &special);
	ft_free_matrix(matrix_copy, size.y);

	if (special.exit_count != 1 || special.map.coins != matrix->coins_collected)
		return (0);
	return (1);
}
