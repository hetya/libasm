
# ~~~~~~~~~~ LIB ~~~~~~~~~~
NAME = libasm.a

LIB_SRCS= ft_read.s\
		ft_strcmp.s\
		ft_strcpy.s\
		ft_strdup.s\
		ft_strlen.s\
		ft_write.s

LIB_SRCS_DIR= lib/src

LIB_OBJS_DIR= lib/objs
# LIB_OBJS= $(LIB_SRCS:.s=.o)
LIB_OBJS= $(addprefix $(LIB_OBJS_DIR)/, $(LIB_SRCS:.s=.o))


NASM = nasm
NASM_FLAGS = -f elf64

# ~~~~~~~~~~ TEST ~~~~~~~~~~

TEST_NAME = test_libasm

TEST_SRCS=main.c

TEST_SRCS_DIR= test/src

TEST_INCLUDES=libasm.h
TEST_INCLUDES_DIR=test/includes

TEST_OBJS_DIR= test/objs
TEST_OBJS= $(addprefix $(TEST_OBJS_DIR)/, $(TEST_SRCS:.c=.o))

CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGS += -fsanitize=address -g3


# ~~~~~~~~~ COMPILE LIBASM ~~~~~~~~~~

$(LIB_OBJS_DIR)/%.o: $(LIB_SRCS_DIR)/%.s Makefile
		printf "$(GREEN)Compiling: $< $(END)\n"
		mkdir -p $(LIB_OBJS_DIR)
		$(NASM) $(NASM_FLAGS) $< -o $@

$(NAME): $(LIB_OBJS)
		ar rcs $(NAME) $(LIB_OBJS)

all: $(NAME)


# ~~~~~~~~~~~ COMPILE TEST ~~~~~~~~~~

$(TEST_OBJS_DIR)/%.o: $(TEST_SRCS_DIR)/%.c Makefile $(TEST_INCLUDES_DIR)/$(TEST_INCLUDES)
	printf "$(GREEN)Compiling: $< $(END)\n"
	mkdir -p $(TEST_OBJS_DIR)
	$(CC) $(FLAGS) -I$(TEST_INCLUDES_DIR) -c $< -o $@

test $(TEST_NAME): $(TEST_OBJS) $(NAME) Makefile
	printf $(TEST_OBJS)
	$(CC) $(FLAGS) $(TEST_OBJS) -L. -lasm -o $(TEST_NAME)


# ~~~~~~~~~~~ CLEAN ~~~~~~~~~~~

clean:
		rm -rf $(LIB_OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re : fclean all


# ~~~~~~~~~~~ COLORS ~~~~~~~~~~~~
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
END = \033[0m

.PHONY: all clean fclean re
.SILENT: 