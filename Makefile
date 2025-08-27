NAME = push_swap

DIRECTORY = ./project

SOURCE = $(DIRECTORY)/src

LIBFT = $(SOURCE)/libft
PUSH_SWAP = $(SOURCE)/push_swap

LIBRARY = $(DIRECTORY)/library

PUSH_SWAP_A = $(LIBRARY)/push_swap.a
LIBFT_A = $(LIBRARY)/libft.a

CC = cc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(PUSH_SWAP_A) $(LIBFT_A)
	@$(CC) $^ -o $@
	
$(PUSH_SWAP_A): $(PUSH_SWAP)
	@$(MAKE) -C $(PUSH_SWAP) -s

$(LIBFT_A): $(LIBFT)
	@$(MAKE) -C $(LIBFT) -s
	
clean:
	@$(MAKE) -C $(PUSH_SWAP) fclean -s
	@$(MAKE) -C $(LIBFT) fclean -s
	
fclean: clean
	@rm -rf $(NAME)

	
re: fclean all

.PHONY: all clean fclean re bonus
