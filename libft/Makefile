NAME = libft.a

SRC = $(addsuffix .c, $(addprefix ft_, \
	isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy \
	memmove strlcpy strlcat toupper tolower strchr strrchr strncmp memchr \
	memcmp strnstr atoi calloc strdup substr strjoin strtrim split itoa \
	strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd))

BONUS_SRC = $(addsuffix .c, $(addprefix ft_, \
	lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear \
	lstiter lstmap))

OBJS := $(SRC:.c=.o)
BONUS_OBJS := $(BONUS_SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

# archive
AR = ar
ARFLAGS = -rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus: $(OBJS) $(BONUS_OBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o: %.c
	$(CC) -c $(CFLAGS) -MMD $< -o $@
	-include $(OBJS:.o=.d)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(OBJS:.o=.d) $(BONUS_OBJS:.o=.d)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
