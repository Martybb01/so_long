/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:31:56 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/04 13:18:58 by marboccu         ###   ########.fr       */
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

void dfs(char **map, t_point size, t_point curr, t_data *special)
{
	if (curr.x < 0 || curr.x + 1 >= size.x || curr.y < 0 || curr.y + 1 >= size.y || map[curr.y][curr.x] == '1')
		return;
	if (map[curr.y][curr.x] == 'E')
		special->exit_count++;
	else if (map[curr.y][curr.x] == 'C')
		special->map.coins++;

	map[curr.y][curr.x] = '1';
	dfs(map, size, (t_point){curr.x - 1, curr.y}, special);
	dfs(map, size, (t_point){curr.x, curr.y - 1}, special);
	dfs(map, size, (t_point){curr.x + 1, curr.y}, special);
	dfs(map, size, (t_point){curr.x, curr.y + 1}, special);
}

int is_reachable(t_data *matrix)
{
	t_point curr;
	t_point size;
	t_data special;

	curr = ft_find_player(matrix->map.map);

	size.x = matrix->size.x;
	size.y = matrix->size.y;

	special.map.coins = 0;
	special.exit_count = 0;

	dfs(matrix->map.map, size, curr, &special);
	if (special.exit_count != 0 || special.map.coins != matrix->coins_collected)
		return (0);
	return (1);
}

void ft_check_map(t_data *game)
{
	if (!is_reachable(game))
		ft_error("ERROR: MAP IS NOT REACHABLE!");
}
