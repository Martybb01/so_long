#include "so_long.h"

int ft_matlen(char **matrix)
{
	int i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
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
	matrix->coins_collected = 0;
	while (matrix->map.map[i])
	{
		j = 0;
		while (matrix->map.map[i][j])
		{
			if (matrix->map.map[i][j] == 'C')
				matrix->coins_collected++;
			j++;
		}
		i++;
	}
}

void ft_render_image(t_data *window)
{
	window->img.player_up = mlx_xpm_file_to_image(window->mlx, "textures/char2.xpm", &window->size_x, &window->size_y);
	window->img.player_down = mlx_xpm_file_to_image(window->mlx, "textures/char1.xpm", &window->size_x, &window->size_y);
	window->img.player_left = mlx_xpm_file_to_image(window->mlx, "textures/char4.xpm", &window->size_x, &window->size_y);
	window->img.player_right = mlx_xpm_file_to_image(window->mlx, "textures/char3.xpm", &window->size_x, &window->size_y);
	window->img.empty_0 = mlx_xpm_file_to_image(window->mlx, "textures/floor.xpm", &window->size_x, &window->size_y);
	window->img.wall_1 = mlx_xpm_file_to_image(window->mlx, "textures/wall.xpm", &window->size_x, &window->size_y);
	window->img.coll_c = mlx_xpm_file_to_image(window->mlx, "textures/collectible.xpm", &window->size_x, &window->size_y);
	window->img.exit_e = mlx_xpm_file_to_image(window->mlx, "textures/door.xpm", &window->size_x, &window->size_y);
}

void ft_fill_term(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < BUFFERINO)
	{
		j = 0;
		while (j < data->size_x * IMG_WIDTH)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, j, i, 0xff3900);
			j++;
		}
		i++;
	}
}

void ft_put_map(t_data *matrix, int keycode)
{
	int i;
	int j;

	i = 0;
	ft_fill_term(matrix);
	while (matrix->map.map[i])
	{
		j = 0;
		while (matrix->map.map[i][j])
		{
			if (matrix->map.map[i][j] == '1')
				mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.wall_1, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
			else if (matrix->map.map[i][j] == '0')
				mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.empty_0, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
			else if (matrix->map.map[i][j] == 'C')
				mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.coll_c, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
			else if (matrix->map.map[i][j] == 'P')
			{
				matrix->player_x = j;
				matrix->player_y = i;
				if (keycode == 'w' || keycode == ARROW_UP)
					mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.player_up, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
				else if (keycode == 's' || keycode == ARROW_DOWN)
					mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.player_down, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
				else if (keycode == 'a' || keycode == ARROW_LEFT)
					mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.player_left, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
				else if (keycode == 'd' || keycode == ARROW_RIGHT)
					mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.player_right, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
			}
			else if (matrix->map.map[i][j] == 'E')
				mlx_put_image_to_window(matrix->mlx, matrix->mlx_win, matrix->img.exit_e, j * IMG_HEIGHT, i * IMG_WIDTH + BUFFERINO);
			j++;
		}
		i++;
	}
}
