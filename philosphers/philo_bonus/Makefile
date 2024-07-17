# Variables
NAME = philo_bonus

SRC_DIR = src

OBJ_DIR = obj

SRC_FILES = main.c utils.c init_free.c philo_routine.c errors_eaten.c

# Convert to object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

INCLUDES = -I$(SRC_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

# Compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

run: all
	$(NAME)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run bonus