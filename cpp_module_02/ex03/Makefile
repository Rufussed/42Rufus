# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/02 17:29:12 by rlane             #+#    #+#              #
#    Updated: 2025/01/07 14:00:41 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp Fixed.cpp Point.cpp
OBJ = $(SRC:.cpp=.o)
NAME = bsp

GREEN = \033[0;32m
RESET = \033[0m
YELLOW = \033[0;33m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

test: $(NAME)
	@echo "\n$(GREEN)Running Test 1.$(RESET) point is inside the triangle\n"
	@./$(NAME) 0 0 0 4 4 0 1 1
	@echo "Test 1 complete. Should be $(GREEN)inside$(RESET)\n"
	@echo "\n$(YELLOW)Running Test 2.$(RESET) point is outside the triangle\n"
	@./$(NAME) 0 0 0 4 4 0 5 5
	@echo "Test 2 complete. Should be $(YELLOW)on or outside$(RESET)\n"
	@echo "\n$(YELLOW)Running Test 3.$(RESET) point is outside the triangle\n"
	@./$(NAME) 0 0 0 4 4 0 0 0
	@echo "Test 3 complete. Should be $(YELLOW)on or outside$(RESET)\n"
	@echo "\n$(GREEN)Running Test 4.$(RESET) point is just inside the triangle\n"
	@./$(NAME) 0 0 0 4 4 0 0.01 3.98
	@echo "Test 4 complete. Should be $(GREEN)inside$(RESET)\n"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all