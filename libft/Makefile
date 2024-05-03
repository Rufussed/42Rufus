# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asomanah <asomanah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 10:00:06 by asomanah          #+#    #+#              #
#    Updated: 2024/05/03 14:57:57 by asomanah         ###   ########.fr        #
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

INC_DIR = .

OBJS_ALL = $(OBJ) $(BONUS_OBJ)

OBJ = $(SRC:%.c=%.o)

BONUS_OBJ = $(BONUS_SRC:%.c=%.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I$(INC_DIR)

RANNAME = ranlib $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	$(RANNAME)
	
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

bonus: $(OBJS_ALL)
	ar rcs $(NAME) $(OBJS_ALL)
	$(RANNAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean remake
