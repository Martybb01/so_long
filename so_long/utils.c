/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:21:34 by marboccu          #+#    #+#             */
/*   Updated: 2023/11/30 23:22:55 by marboccu         ###   ########.fr       */
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
