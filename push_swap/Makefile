# Variables
NAME = push_swap
BONUS_NAME = checker

SRC_DIR = src
BONUS_SRC_DIR = bonus_src
OBJ_DIR = obj
BONUS_OBJ_DIR = obj_bonus

SRC_FILES = main.c init.c data_checkers.c linked_list.c free_error.c rules1.c rules2.c rules3.c sort1.c sort2.c sort3.c sort4.c sort5.c sort6.c print.c 
BONUS_SRC_FILES = main_bonus.c init_bonus.c data_checkers_bonus.c linked_list_bonus.c free_error_bonus.c rules1_bonus.c rules2_bonus.c rules3_bonus.c print_bonus.c get_instructions_bonus.c

# Convert to object files
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
BONUS_OBJS = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_SRC_FILES:.c=.o))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I$(SRC_DIR) -I$(BONUS_SRC_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(NAME)

bonus: $(BONUS_NAME) 

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

# Compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BONUS_OBJ_DIR):
	mkdir -p $(BONUS_OBJ_DIR)

$(LIBFT):
	@make -C $(LIBFT_DIR)

run: all
	$(NAME)

clean:
	@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) 
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re run bonus