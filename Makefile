NAME = libasm.a
# SRCS= ft_read.s\
# 		ft_strcpy.s\
# 		ft_strcmp.s\
# 		ft_strdup.s\
# 		ft_strlen.s\
# 		ft_write.s
SRCS= ft_strlen.s
SRCS_DIR= src

OBJS_DIR= objs
# OBJS= $(SRCS:.s=.o)
OBJS= $(addprefix $(OBJS_DIR)/, $(SRCS:.s=.o))


NASM = nasm
NASM_FLAGS = -f elf64

CC = gcc
FLAGS = -Wall -Wextra -Werror

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.s Makefile
		printf "$(GREEN)Compiling: $< $(END)\n"
		mkdir -p $(OBJS_DIR)
		$(NASM) $(NASM_FLAGS) $< -o $@

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

all: $(NAME)

test: $(NAME) main.c Makefile
		$(CC) $(FLAGS) -L $(NAME) main.c $(NAME) -o test

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re : fclean all

# COLORS
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
END = \033[0m

.PHONY: all clean fclean re
.SILENT: 