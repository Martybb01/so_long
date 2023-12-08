/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:48:43 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/08 03:58:50 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// function to control if the map file is a .ber file and exists
int ft_checkfile(int ac, char *file)
{
	if (ac != 2)
	{
		ft_error("Usage: ./so_long maps/file.ber", NULL);
		return 0;
	}
	else if (!ft_match_ext(file, ".ber"))
	{
		ft_error("MAP FILE IS NOT A .ber FILE", NULL);
	}
	else if (open(file, O_RDONLY) == -1)
	{
		ft_error("MAP FILE DOES NOT EXIST", NULL);
	}
	return (1);
}

void ft_is_maprect(t_data *matrix)
{
	int i;

	i = 0;
	while (matrix->map.map[i] && matrix->map.map[i + 1])
	{
		if (ft_strlen(matrix->map.map[i]) != ft_strlen(matrix->map.map[i + 1]))
			ft_error("MAP IS NOT RECTANGULAR", matrix->map.map);
		i++;
	}
}

void ft_checkwalls(t_data *matrix)
{
	int i;
	int j;

	i = 0;
	while (matrix->map.map[i])
	{
		j = 0;
		while (matrix->map.map[i][j])
		{
			if (i == 0 || j == 0 || i == matrix->size.y - 1 || j == matrix->size.x - 1)
			{
				if (matrix->map.map[i][j] != '1')
					ft_error("MAP IS NOT CLOSED", matrix->map.map);
			}
			ft_wrong_char(matrix->map.map[i][j], matrix->map.map);
			j++;
		}
		i++;
	}
}

int ft_check_empty_lines(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void ft_checkerrors(t_data *matrix)
{
	if (matrix->coins_collected == 0)
		ft_error("NO DROPS, THE FLOOR IS TOO LAVA", matrix->map.map);
	if (matrix->player_count != 1)
		ft_error("WRONG NUMBER OF PLAYERS", matrix->map.map);
	if (matrix->exit_count != 1)
		ft_error("WRONG NUMBER OF EXITS", matrix->map.map);
	if (!ft_is_reachable(matrix))
		ft_error("MAP IS NOT REACHABLE", matrix->map.map);
	ft_checkwalls(matrix);
	ft_is_maprect(matrix);
}
