# Variables
NAME = so_long
SRC = main.c check_map.c path_finding.c move.c draw_map_win.c read_map_free.c event_handlers.c  initialise_report.c pathfinder_list_init_free.c 
OBJS = $(SRC:.c=.o)
MLX_DIR = mlx
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone $(MLX_REPO) $(MLX_DIR); \
	fi
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

run: $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re run
