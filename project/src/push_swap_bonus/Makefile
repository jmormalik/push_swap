CC = cc -c -Wall -Wextra -Werror -g
NAME = push_swap_bonus.a

INC = -I ../../includes
LIB = ../../library

SRCS = \
main.c  ps_split.c  push.c  r_rotate.c rotate.c  swap.c  utils.c convert.c sort.c short_sort.c free_list.c\


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
