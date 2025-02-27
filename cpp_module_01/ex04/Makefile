# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 15:28:20 by rlane             #+#    #+#              #
#    Updated: 2024/12/19 18:40:57 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
NAME = sed_is_for_losers

# Colors
GREEN    = \033[32m
RESET    = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJ)

test: $(NAME)
	@echo "\n$(GREEN)Running Test 1.$(RESET) Only partial replacement text in file: "
	@./$(NAME) tests/test_1.txt text_to_find replaced
	@echo "Test 1 complete. Should be $(GREEN)0 replacements$(RESET)\n"

	@echo "$(GREEN)Running Test 2.$(RESET) Consecutive replacements in file: "
	@./$(NAME) tests/test_2.txt text_to_find replaced
	@echo "Test 2 complete. Should be $(GREEN)5 replacements$(RESET)\n"

	@echo "$(GREEN)Running Test 3.$(RESET) C++ to Bananas+++: "
	@./$(NAME) tests/test_3.txt C++ Bananas+++
	@echo "Test 3 complete.  Should be $(GREEN)5 replacements$(RESET)\n"

	@echo "$(GREEN)Running Test 4.$(RESET) Empty file: "
	@./$(NAME) tests/test_4.txt text_to_find replaced
	@echo "Test 4 complete. Should be $(GREEN)0 replacements$(RESET)\n"

	@echo "$(GREEN)Running Test 5.$(RESET) No search matches: "
	@./$(NAME) tests/test_5.txt text_to_find replaced
	@echo "Test 5 complete. Should be $(GREEN)0 replacements$(RESET)\n"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all test clean fclean re