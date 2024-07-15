# Variables
NAME = philo
BONUS_NAME = 

SRC_DIR = src
BONUS_SRC_DIR = bonus_src
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus

SRC_FILES = main.c utils.c init_free.c philo_routine.c errors.c
BONUS_SRC_FILES = 

# Convert to object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC_FILES:.c=.o))

INCLUDES = -I$(SRC_DIR) -I$(BONUS_SRC_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

bonus: $(BONUS_NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

# Compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

run: all
	$(NAME)

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) 

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re run bonus