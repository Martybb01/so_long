/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:48:43 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/02 03:15:34 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *errormessage)
{
	ft_printf("\n###############################\n%s\n###############################\n\n", errormessage);
	exit(1);
}

// function to control if the map file is a .ber file and exists
int ft_checkfile(int ac, char *file)
{
	if (ac != 2)
	{
		ft_error("Usage: ./so_long file.ber");
		return 0;
	}
	else if (!ft_match_ext(file, ".ber"))
		ft_error("MAP FILE IS NOT A .ber FILE");
	return (1);
}

void ft_is_maprect(t_data *matrix)
{
	int i;
	int j;

	i = 0;
	while (matrix->map.map[i])
	{
		j = 0;
		while (matrix->map.map[j])
		{
			if (matrix->map.map[i][j] == '\0')
				ft_error("MAP IS NOT RECTANGULAR");
			j++;
		}
		i++;
	}
}

int ft_wrong_char(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		ft_error("MAP CONTAINS WRONG CHARS");
	return (0);
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
					ft_error("MAP IS NOT CLOSED");
			}
			ft_wrong_char(matrix->map.map[i][j]);
			j++;
		}
		i++;
	}
}

void ft_checkerrors(t_data *matrix)
{
	if (matrix->coins_collected == 0)
		ft_error("NO DROPS, THE FLOOR IS TOO LAVA");
	if (matrix->player_count != 1)
		ft_error("WRONG NUMBER OF PLAYERS");
	if (matrix->exit_count != 1)
		ft_error("WRONG NUMBER OF EXITS");
	ft_checkwalls(matrix);
}
