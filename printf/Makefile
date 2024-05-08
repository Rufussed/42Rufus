# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by rlane             #+#    #+#              #
#    Updated: 2024/05/08 18:21:33 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = $(addsuffix .c, $(addprefix ft_, \
	count_elements_base format_printers_1 format_printers_2 printf \
	putchar_fd putstr_fd putnbr_fd putnbr_hex strlen))

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