# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 13:30:01 by rlane             #+#    #+#              #
#    Updated: 2024/06/14 13:30:02 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = so_long
SRC = main_bonus.c check_map_bonus.c path_finding_bonus.c move_bonus.c draw_map_win_bonus.c read_map_free_bonus.c event_handlers_bonus.c  initialise_report_bonus.c pathfinder_list_init_free_bonus.c enemies_bonus.c

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
