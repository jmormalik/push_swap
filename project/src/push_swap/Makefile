CC = cc -c -Wall -Wextra -Werror
NAME = push_swap.a

INC = -I ../../includes
LIB = ../../library

SRCS = \
main.c  ps_split.c  push.c  rotate.c  swap.c  utils.c convert.c sort.c \


OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $^ -o $@ $(INC)

$(NAME): $(OBJS)
	@mkdir -p ../../library
	@ar -rcs $(LIB)/$(NAME) $^

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(LIB)/$(NAME)

re: fclean all

.PHONY: all clean fclean re
