# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 13:30:01 by rlane             #+#    #+#              #
#    Updated: 2024/07/01 19:24:28 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = push_swap
BONUS_NAME = push_swap_bonus

SRC_FILES = main.c init.c data_checkers.c linked_list.c free_error.c rules1.c rules2.c rules3.c sort1.c sort2.c sort3.c sort4.c sort5.c sort6.c print.c 

BONUS_SRC_FILES = 

# Convert to object files
OBJS = $(SRC_FILES:.c=.o)
BONUS_OBJS = $(BONUS_SRC_FILES:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

bonus: $(BONUS_NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

# Compilation rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

run: all
	$(NAME)

clean:
	@rm -f $(OBJS)  $(BONUS_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re run bonus
