# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by rlane             #+#    #+#              #
#    Updated: 2024/05/11 11:06:36 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(addsuffix .c, $(addprefix ft_, \
	isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy \
	memmove strlcpy strlcat toupper tolower strchr strrchr strncmp memchr \
	memcmp strnstr atoi calloc strdup substr strjoin strtrim split itoa \
	strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd))

BONUS_SRC = $(addsuffix _bonus.c, $(addprefix ft_, \
	lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear \
	lstiter lstmap))

# Including directory
INC_DIR = .

# Object files for main and bonus
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)

MAKE = make

# Path to the printf library
PRINTF = printf/libftprintf.a

# Default target
all: $(NAME) $(PRINTF) # Modified to include printf library

# Main library compilation
$(NAME): $(OBJ)
	ar rcs $@ $^
	ranlib $@

# Object file compilation
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# Bonus files compilation
# Modified to include printf library
bonus: $(OBJ) $(BONUS_OBJ) $(PRINTF)
	ar rcs $(NAME) $^
	ranlib $(NAME)

# Rule to make the printf library
$(PRINTF):
	$(MAKE) -C printf

# Clean object files, modified to clean printf objects
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) -C printf clean 

# Fully clean the project
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C printf fclean # Modified to fully clean printf

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re
