# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by asomanah          #+#    #+#              #
#    Updated: 2024/05/03 15:34:07 by rlane            ###   ########.fr        #
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
bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $^
	ranlib $(NAME)

# Clean object files
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

# Fully clean the project
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re