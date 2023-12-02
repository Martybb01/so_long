/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:21:34 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/02 02:52:47 by marboccu         ###   ########.fr       */
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

int ft_matlen(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int ft_match_ext(char *map, char *ext)
{
	int map_len;
	int ext_len;

	map_len = ft_strlen(map);
	ext_len = ft_strlen(ext);
	if (map_len < ext_len)
		return (0);
	map += map_len - ext_len;
	while (*map)
	{
		if (*map != *ext)
			return (0);
		map++;
		ext++;
	}
	return (1);
}
