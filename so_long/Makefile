# Variables
NAME = so_long
SRC = main.c
OBJS = $(SRC:.c=.o)
MLX_LIB = mlx/
MLX_LIB_PATH = mlx/libmlx_Linux.a
MLX_FLAGS = -Lmlx -lmlx_Linux -L/usr/lib/X11 -lXext -lX11 -lm -lz
LIBFT = libft/libft.a
INCLUDES = -Imlx -Ilibft
CC = cc
#CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)
CFLAGS =  -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB_PATH)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB_PATH):
	@if [ ! -d "mlx" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git mlx; \
	fi
	@make -C $(MLX_LIB)

$(LIBFT):
	@make -C libft

run: $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(MLX_LIB)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re run
