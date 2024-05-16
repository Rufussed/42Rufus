# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by rlane             #+#    #+#              #
#    Updated: 2024/05/16 12:36:14 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_format_handlers.c ft_char_functions.c ft_putnbr_functions.c

# Including directory
INC_DIR = .

# Object files for main and bonus
OBJ = $(SRC:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

# Default target
all: $(NAME)

# Main library compilation
$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

# Object file compilation
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJ)

# Fully clean the project
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re