# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlane <rlane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 11:13:02 by rlane             #+#    #+#              #
#    Updated: 2024/04/25 19:24:31 by rlane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# This Makefile is a complete example to compile a C library.

# SRC is a variable containing all the mandatory source files
# As you can see, I simply put the file names without the .c extension
# the .c extension is added to each file with the addsuffix filename function
# this filename function has the following prototype
# $(addsuffix suffix, names…)
# The suffix will be added to every file name you add as second argument.
SRC = $(addsuffix .c, \
	ft_isalpha \
	ft_isdigit \
	ft_isalnum \
	ft_isascii \
	ft_isprint \
	ft_strlen \
	ft_memset \
	ft_bzero \
	ft_memcpy \
	ft_memmove \
	ft_strlcpy \
	ft_strlcat \
	ft_toupper \
	ft_tolower \
	ft_strchr \
	ft_strrchr \
	ft_strncmp \
	ft_memchr \
	ft_memcmp \
	ft_strnstr \
	ft_atoi \
	ft_calloc \
	ft_strdup \
	ft_substr \
	ft_strjoin \
	ft_strtrim \
	ft_split \
	ft_itoa \
	)


# OBJS is a variable containing all .o filenames.
# As you can see I wrote OBJS := and not OBJS =
# The difference between := and = is that = is an assignement operator 
# like we know in C. := tells make to append the result to the variable
# We have to append the result because what's on the right will be run for
# every .c file one by one.
# Whats on the right basically means : "for every .c file you find in the
# SRC variable, give me the corresponding .o filename".
# This will then append the result for each .c file to the OBJ variable.
# It simply replaces the .c from each file in the SRC variable by .o
OBJS := $(SRC:%.c=%.o)

# BONUS_SRC is a variable containing all the bonus source files
# As you can see, I simply put the file names without the .c extension
# the .c extension is added to each file with the addsuffix filename function
# this filename function has the following prototype
# $(addsuffix suffix, names...)
# The suffix will be added to every file name you add as second argument.
# Then I added an $(addprefix, names...) filename function around it to
# add a prefix for the bonus directory. 
# The $(addprefix, names...). works like the addsuffix function but
# instead of adding the text at the end of each filename, it adds it to
# the start of each filename.
#BONUS_SRC = $(addprefix bonus/, $(addsuffix _bonus.c, ft_lstnew ft_lstadd_back ft_lstadd_front ))

# BONUS_OBJS is a variable containing all bonus .o filenames.
# This works the same way as the OBJS variable.
#BONUS_OBJS := $(BONUS_SRC:%.c=%.o)

# SUPP_SRC is a variable containing all the additional source files
# It works the same way as the BONUS_SRC variable, adding the .c suffix
# to every filename, then adding the supp/ prefix to every filename
#SUPP_SRC = $(addprefix supp/, $(addsuffix .c, ft_putchar ft_putstr ft_putnbr))

# SUPP_OBJS is a variable containing all additional .o filenames.
# It works the same way as the OBJS and BONUS_OBJS variables.
#SUPP_OBJS := $(SUPP_SRC:%.c=%.o)

# As I did for the source and object files, I declared some variables for
# things I don't want to write each time.

# NAME is a variable containing the name of the archive we want to create
NAME = libft.a

# CC is a variable containing the compiler
# usually gcc for C and g++ for C++
CC = gcc

# CCFLAGS is a variable containing the compiler flags
# -Wall : this flag enables all the warnings about constructions
# -Wextra : this flag enables some extra warning flags that are not
#          enabled by -Wall
# -Werror : this flag turns all warning into errors to stop the compiler
#         when it encounters a warning.
# You can find what flags are actually enabled when using these flags
# by following this link, it also describes in more details what each
# flag does
# https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html#Warning-Options
CCFLAGS = -Wall -Wextra -Werror

# INC_DIR is a variable containing the path of the include directory
# Include directory is used to put all the .h file needed by your 
# library.
# By including the include directory as a preprocessor flag when compiling
# your files, you don't have to specify the path each time you include a 
# header file. 
# You can simply write #include "main.h" instead of "../include/main.h".
INC_DIR = .

# CPPFLAGS is a variable containing the preprocessor flags
# In this example, it only contains the -I flag which specifies the 
# include directory path taken from the INC_DIR variable.
CPPFLAGS = -I$(INC_DIR)

# RM is an alias variable for the rm -f shell command.
# I say alias variable because I can use this instead of writing
# rm -f each time I have to delete something.
# If I don't put the -f option, using the rm function will generate an
# error if a file does not exist, -f force the execution, wheter or not the
# file to delete exists.
RM = rm -f

# ARNAME is an alias variable for the ar rcs $(NAME) shell command.
ARNAME = ar rcs $(NAME)

# RANNAME is an alias variable for the ranlib $(NAME) shell command.
RANNAME = ranlib $(NAME)

# OBJS_BASBO is a variable containing all the object filenames for the
# mandatory source files as well as the bonus source files.
OBJS_BASBO = $(OBJS) $(BONUS_OBJS)

# OBJS_ALL is a variable containing all the object filenames for the 
# mandatory, bonus and additionnal source files.
OBJS_ALL = $(OBJS_BASBO) $(SUPP_OBJS)

# ALL is the first rule in the Makefile, making it the default rule when
# calling the make command without specifying the rule.
# This rule has the $(NAME) rule as dependency and will therefore,
# call the $(NAME) rule.
all: $(NAME)

# $(NAME) is the main rule of the Makefile.
# This rule has the OBJS variable as a dependency, which means, if one or
# more .o files are missing, make will try to build them (if a rule for
# that exists) before running the $(NAME) commands.
# When all the dependency are there, the commands will be executed.
# The commands are what is described above in the variable declaration
# section :
# ARNAME : ar rcs $(NAME)
# RANNAME : ranlib $(NAME)
$(NAME): $(OBJS)
	$(ARNAME) $(OBJS)
	$(RANNAME)

# %.o rule will compile one .c file to its correspondig object (.o) file
# The %.o: %.c pattern specifies that in order to build something whose
# file name ends with .o, you need to have a file that has the same prefix
# but then ends with .c rather than .o.
# $<: The name of the first prerequisite.
# $@: This corresponds to the name of the target : what is on the left
#     side of the colon.
%.o: %.c
	$(CC) $(CPPFLAGS) $(CCFLAGS) -o $@ -c $<

# CLEAN rule has no prerequisites
# What it does is use the $(RM) alias variable followed by the content of
# the OBJS_ALL variable, that is, every .o filenames.
# This results in all the .o files being deleted.
clean:
	$(RM) $(OBJS_ALL)

# FCLEAN rule has as prerequisite the CLEAN rule, which means that the 
# CLEAN rule will be run first. 
# When the CLEAN rule is done, the fclean commands will be run.
# This results in all the .io files being deleted, as well as the created
# library because it has the name $(NAME)
fclean: clean
	$(RM) $(NAME)

# RE rule has as prerequisites the FCLEAN and ALL rules.
# As the prerequisite are read from left to right, the first rule to be
# executed will be the FCLEAN rule, then we'll have the ALL rule.
# Since there are no commands for the RE rule, once the ALL rule is done,
# the RE rule will also be done.
re: fclean all

# The bonus rule works the same way as the $(NAME) rule but instead of
# having the OBJS variable as dependency, it has the OBJS_BASBO variable.
# Since the OBJS_BASBO variable contains the OBJS and the BONUS_OBJS
# variables, all the .o files contained in these two variables are
# dependencies for this bonus rule.
# The commands are what is described above in the variable declaration
# section :
# ARNAME : ar rcs $(NAME)
# RANNAME : ranlib $(NAME)
bonus: $(OBJS_BASBO)
	$(ARNAME) $(OBJS_BASBO)
	$(RANNAME)

# The bonus rule works the same way as the $(NAME) rule but instead of
# having the OBJS variable as dependency, it has the OBJS_ALL variable.
# Since the OBJS_ALL variable contains the OBJS, the BONUS_OBJS and the
# SUPP_OBJS variables, all the .io files contained in these two variables
# are dependencies for this everything rule.
# The commands are what is described above in the variable declaration
# section :
# ARNAME : ar rcs $(NAME)
# RANNAME : ranlib $(NAME)
everything: $(OBJS_ALL)
	$(ARNAME) $(OBJS_ALL)
	$(RANNAME)
