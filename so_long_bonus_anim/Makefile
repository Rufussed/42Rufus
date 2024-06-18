# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rufus <rufus@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 13:30:01 by rlane             #+#    #+#              #
#    Updated: 2024/06/15 12:19:08 by rufus            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = so_long
BONUS_NAME = so_long_bonus

SRC_DIR = src
BONUS_SRC_DIR = bonus_src
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

# List all regular source files explicitly
SRC_FILES = main.c check_map.c path_finding.c move.c draw_map_win.c \
		read_map_free.c event_handlers.c initialise_report.c \
		pathfinder_list_init_free.c

# List all bonus source files explicitly
BONUS_SRC_FILES = main_bonus.c check_map_bonus.c path_finding_bonus.c ui_bonus.c \
		move_player_bonus.c move_enemy_bonus.c report_errors_bonus.c win_lose_bonus.c\
		draw_map_bonus.c read_map_free_bonus.c event_handlers_bonus.c \
		initialise_bonus.c pathfinder_list_init_free_bonus.c enemies_bonus.c

# Convert to object files
OBJS = $(addprefix $(OBJ_DIR)/,$(SRC_FILES:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR)/,$(BONUS_SRC_FILES:.c=.o))

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/lib/X11 -lXext -lX11 -lm -lz
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(MLX_DIR) -I$(LIBFT_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)  && valgrind ./$(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)  && valgrind ./$(BONUS_NAME)

# Compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%_bonus.o: $(BONUS_SRC_DIR)/%_bonus.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

run: $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re run bonus
