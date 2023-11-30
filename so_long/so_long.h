#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "libft_super/libft.h"
#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
// #include <sys/types.h>
// #include <sys/stat.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define IMG_WIDTH 32
#define IMG_HEIGHT 32
#define ARROW_UP 65362
#define ARROW_DOWN 65364
#define ARROW_LEFT 65361
#define ARROW_RIGHT 65363
#define ESC 65307
#define BUFFERINO 30

typedef struct s_img
{
	void *player_up;
	void *player_down;
	void *player_left;
	void *player_right;
	void *empty_0;
	void *wall_1;
	void *coll_c;
	void *exit_e;
} t_img;

typedef struct s_point
{
	int x;
	int y;
} t_point;
typedef struct s_map
{
	char **map;
	int coins;
} t_map;

typedef struct s_data
{
	void *mlx;
	void *mlx_win;
	t_img img;
	t_map map;
	t_point player_pos;
	t_point size;
	int moves;
	int coins_collected;
} t_data;

int ft_matlen(char **matrix);
char **ft_map_init(char *map, t_data *matrix);
void ft_drop_counter(t_data *matrix);
void ft_render_image(t_data *window);
void ft_fill_term(t_data *data);
void ft_put_map(t_data *matrix, int keycode);
int ft_key_press(int keycode, t_data *matrix);
int ft_window_close(t_data *window);

#endif
