# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by rlane             #+#    #+#              #
#    Updated: 2024/05/16 12:10:47 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = getnextline.a

SRC = get_next_line.c get_next_line_utils.c

BONUS_SRC = get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_utils.c

# Including directory
INC_DIR = .

# Object files for main and bonus
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

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

# Bonus files compilation
bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $^
	ranlib $(NAME)

# Clean object files
clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)

# Fully clean the project
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re