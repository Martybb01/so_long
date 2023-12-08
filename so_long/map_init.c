/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:42:38 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/06 12:24:26 by marboccu         ###   ########.fr       */
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
		ft_error("MAP IS EMPTY", NULL);
	}
}

char *ft_read_map(char *map)
{
	int fd;
	char *line;
	char *buffer;

	buffer = ft_calloc(1, 1);
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
			buffer = ft_freejoin(buffer, line);
			free(line);
		}
		close(fd);
		ft_badmap(buffer);
	}
	return (buffer);
}

char **ft_map_init(char *map, t_data *matrix)
{
	char *buffer;

	buffer = ft_read_map(map);
	if (!buffer)
		ft_error("MAP FILE DOES NOT EXIST", NULL);
	if (ft_check_empty_lines(buffer))
	{
		free(buffer);
		ft_error("MAP CONTAINS EMPTY LINES", NULL);
	}
	matrix->map.map = ft_split(buffer, '\n');
	free(buffer);
	ft_all_counter(matrix);
	return (matrix->map.map);
}
