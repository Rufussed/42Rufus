# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 13:30:01 by rlane             #+#    #+#              #
#    Updated: 2024/06/20 16:26:26 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
NAME = minitalk
BONUS_NAME = minitalk_bonus

CLIENT = client
SERVER = server

BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus

CLIENT_SRC_FILES = client.c
SERVER_SRC_FILES = server.c

BONUS_CLIENT_SRC_FILES = client_bonus.c 
BONUS_SERVER_SRC_FILES = server_bonus.c

# Convert to object files
CLIENT_OBJS = $(CLIENT_SRC_FILES:.c=.o)
SERVER_OBJS = $(SERVER_SRC_FILES:.c=.o)
BONUS_CLIENT_OBJS = $(BONUS_CLIENT_SRC_FILES:.c=.o)
BONUS_SERVER_OBJS = $(BONUS_SERVER_SRC_FILES:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC -fPIE $(INCLUDES)

# Targets
all: $(CLIENT) $(SERVER)

bonus: $(BONUS_CLIENT) $(BONUS_SERVER)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBFT) -o $(CLIENT)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFT) -o $(SERVER)

$(BONUS_CLIENT): $(BONUS_CLIENT_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_CLIENT_OBJS) $(LIBFT) -o $(BONUS_CLIENT)

$(BONUS_SERVER): $(BONUS_SERVER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_SERVER_OBJS) $(LIBFT) -o $(BONUS_SERVER)

# Compilation rules
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_DIR)

run: all
	./$(CLIENT)

clean:
	@rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(BONUS_CLIENT_OBJS) $(BONUS_SERVER_OBJS)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re run bonus
