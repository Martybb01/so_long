/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marboccu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:42:38 by marboccu          #+#    #+#             */
/*   Updated: 2023/12/02 02:19:40 by marboccu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	}
	matrix->map.map = ft_split(buffer, '\n');
	ft_drop_counter(matrix);
	return (matrix->map.map);
}

void ft_drop_counter(t_data *matrix)
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

void ft_render_image(t_data *window)
{
	window->img.player[0] = mlx_xpm_file_to_image(window->mlx,
												  "textures/char2.xpm", &window->size.x, &window->size.y);
	window->img.player[1] = mlx_xpm_file_to_image(window->mlx,
												  "textures/char1.xpm", &window->size.x, &window->size.y);
	window->img.player[2] = mlx_xpm_file_to_image(window->mlx,
												  "textures/char4.xpm", &window->size.x, &window->size.y);
	window->img.player[3] = mlx_xpm_file_to_image(window->mlx,
												  "textures/char3.xpm", &window->size.x, &window->size.y);
	window->img.empty_0 = mlx_xpm_file_to_image(window->mlx,
												"textures/floor.xpm", &window->size.x, &window->size.y);
	window->img.wall_1 = mlx_xpm_file_to_image(window->mlx, "textures/wall.xpm",
											   &window->size.x, &window->size.y);
	window->img.coll_c = mlx_xpm_file_to_image(window->mlx,
											   "textures/collectible.xpm", &window->size.x, &window->size.y);
	window->img.exit_e = mlx_xpm_file_to_image(window->mlx, "textures/door.xpm",
											   &window->size.x, &window->size.y);
}

void ft_fill_term(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < BUFFERINO)
	{
		j = 0;
		while (j < data->size.x * IMG_WIDTH)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, j, i, 0xff3900);
			j++;
		}
		i++;
	}
}

int ft_direction(int keycode)
{
	if (keycode == 'w' || keycode == ARROW_UP)
		return (0);
	else if (keycode == 's' || keycode == ARROW_DOWN)
		return (1);
	else if (keycode == 'a' || keycode == ARROW_LEFT)
		return (2);
	else
		return (3);
}

void ft_put_img(t_data *matrix, t_img *img, int j, int i)
{
	mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, img, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
}

void ft_put_map(t_data *matrix, int keycode)
{
	int i;
	int j;

	i = -1;
	ft_fill_term(matrix);
	while (matrix->map.map[++i])
	{
		j = -1;
		while (matrix->map.map[i][++j])
		{
			if (matrix->map.map[i][j] == '1')
				ft_put_img(matrix, matrix->img.wall_1, j, i);
			else if (matrix->map.map[i][j] == '0')
				ft_put_img(matrix, matrix->img.empty_0, j, i);
			else if (matrix->map.map[i][j] == 'C')
				ft_put_img(matrix, matrix->img.coll_c, j, i);
			else if (matrix->map.map[i][j] == 'P')
			{
				matrix->player_pos = (t_point){j, i};
				ft_put_img(matrix, matrix->img.player[ft_direction(keycode)], j, i);
			}
			else if (matrix->map.map[i][j] == 'E')
				ft_put_img(matrix, matrix->img.exit_e, j, i);
		}
	}
}
