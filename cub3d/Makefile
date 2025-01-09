# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 13:30:01 by rlane             #+#    #+#              #
#    Updated: 2025/01/09 14:21:46 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = cub3d
BONUS_NAME = cub3d_bonus

SRC_DIR = src
BONUS_SRC_DIR = bonus_src
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

# List all regular source files explicitly
SRC_FILES = main.c draw_shapes.c event_handlers.c minimap.c vector_math.c parse_map.c
# List all bonus source files explicitly
BONUS_SRC_FILES = 

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
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# add to line above for testing: && valgrind ./$(NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(MLX_LIB)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)  
	
# add to line above for testing: && valgrind ./$(BONUS_NAME)

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
