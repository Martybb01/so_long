/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:21:34 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/09 02:45:38 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define GL_SILENCE_DEPRECATION

void	ft_error(char *errormessage, char **matrix)
{
	if (matrix)
		ft_free_matrix(matrix);
	ft_printf("\n#########################\n%s\n#########################\n\n",
		errormessage);
	exit(1);
}

int	ft_window_close(t_data *window)
{
	ft_free_imgs(window);
	ft_free_matrix(window->map.map);
	mlx_destroy_window(window->mlx, window->mlx_win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	exit(0);
	return (0);
}

int	ft_matlen(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int	ft_match_ext(char *map, char *ext)
{
	int	map_len;
	int	ext_len;

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

int	ft_wrong_char(char c, char **map)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		ft_error("MAP CONTAINS WRONG CHARS", map);
	return (0);
}
