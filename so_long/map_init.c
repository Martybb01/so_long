/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:42:38 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/04 23:50:28 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_all_counter(t_data *matrix)
{
	int i;
	int j;

	i = 0;
	while (matrix->map.map[i])
	{
		j = 0;
		while (matrix->map.map[i][j])
		{
			if (matrix->map.map[i][j] == 'C')
				matrix->coins_collected++;
			if (matrix->map.map[i][j] == 'P')
				matrix->player_count++;
			if (matrix->map.map[i][j] == 'E')
				matrix->exit_count++;
			j++;
		}
		i++;
	}
}

void ft_badmap(char *buffer)
{
	if (ft_strlen(buffer) == 0)
	{
		free(buffer);
		ft_error("MAP IS EMPTY");
	}
}

char **ft_map_init(char *map, t_data *matrix)
{
	int fd;
	char *line;
	char *buffer;

	buffer = malloc(1);
	if (!buffer)
		return (NULL);
	fd = open(map, O_RDONLY);
	if (fd != -1)
	{
		while (1)
		{
			line = get_next_line(fd);
			if (!line)
				break;
			buffer = ft_strjoin(buffer, line);
			free(line);
		}
		// close(fd);
		ft_badmap(buffer);
	}
	if (ft_check_empty_lines(buffer))
		ft_error("MAP CONTAINS EMPTY LINES");
	matrix->map.map = ft_split(buffer, '\n');
	ft_all_counter(matrix);
	return (matrix->map.map);
}
