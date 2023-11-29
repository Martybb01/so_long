NAME = so_long
CC = gcc
CFLAGS = -Wextra -Werror -Wall -g
LINKS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
RM = rm -f

MINILIBX = mlx/libmlx.a
LIBFT = libft_super/libft.a

SRC = main.c \
map_init.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib_comp mlx_comp comp

lib_comp:
	make -C libft_super/
mlx_comp:
	make -C mlx/

comp:
	$(CC) $(CFLAGS) $(LINKS) $(SRC) $(LIBFT) $(MINILIBX) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C libft_super/
	$(RM) $(NAME)

re: fclean all
