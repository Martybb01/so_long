NAME = so_long
CC = gcc
CFLAGS = -Wextra -Werror -Wall -g
LINKS = -I /usr/X11/include -g -L /usr/X11/lib -lX11 -lmlx -lXext
LINKS_LINUX = -lX11 -lm -lXext
RM = rm -f

MINILIBX = mlx/libmlx.a
LIBFT = libft_super/libft.a

SRC = main.c \
map_init.c \
move.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib_comp mlx_comp comp
# ifeq ($(shell uname -s), Darwin)
# 	make comp
# else
# 	make comp_linux
# endif

lib_comp:
	make -C libft_super/
mlx_comp:
	make -C mlx/

comp:
	$(CC) $(CFLAGS) $(LINKS) $(SRC) $(LIBFT) $(MINILIBX) -o $(NAME)

comp_linux:
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(MINILIBX) $(LINKS_LINUX) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	make clean -C mlx/
	make clean -C libft_super/
	$(RM) $(NAME)

re: fclean all
