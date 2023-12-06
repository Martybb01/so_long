/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:58:55 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/05 23:08:42 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_free_imgs(t_data *mlx)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.player[i]);
		i++;
	}
	mlx_destroy_image(mlx->mlx, mlx->img.empty_0);
	mlx_destroy_image(mlx->mlx, mlx->img.wall_1);
	mlx_destroy_image(mlx->mlx, mlx->img.coll_c);
	mlx_destroy_image(mlx->mlx, mlx->img.exit_e);
}

void ft_free_matrix(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
