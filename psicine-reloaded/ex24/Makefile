# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42berlin.de>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:20:21 by rlane             #+#    #+#              #
#    Updated: 2024/04/20 06:44:49 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ./srcs/
HEADER = ./includes/*.h
FLAGS = -Wall -Wextra -Werror

# -c flag compiles object files but does not link
OPTION = -c $(HEADER)

FILES = $(SRC)ft_putchar.c $(SRC)ft_putstr.c $(SRC)ft_strcmp.c $(SRC)ft_strlen.c $(SRC)ft_swap.c

# main target
all: $(NAME)

# create library
# ar is archive, r is replace or insert, c create silently (no output message)
$(NAME):
	gcc $(FLAGS) $(OPTION) $(FILES) $(HEADER)
	ar rc $(NAME) *.o

#clean object files
clean:
	/bin/rm -f *.o

#clean everything
fclean: clean
	/bin/rm -f $(NAME)

#rebuild project
re: fclean all
