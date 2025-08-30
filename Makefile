NAME = push_swap
BONUS = checker

DIRECTORY = ./project

SOURCE = $(DIRECTORY)/src

LIBFT = $(SOURCE)/libft
PUSH_SWAP = $(SOURCE)/push_swap
PUSH_SWAP_BONUS = $(SOURCE)/push_swap_bonus

LIBRARY = $(DIRECTORY)/library

PUSH_SWAP_A = $(LIBRARY)/push_swap.a
PUSH_SWAP_BONUS_A = $(LIBRARY)/push_swap_bonus.a
LIBFT_A = $(LIBRARY)/libft.a

CC = cc -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(PUSH_SWAP_A) $(LIBFT_A)
	@$(CC) $^ -o $@
	
$(PUSH_SWAP_A): $(PUSH_SWAP)
	@$(MAKE) -C $(PUSH_SWAP) -s

$(LIBFT_A): $(LIBFT)
	@$(MAKE) -C $(LIBFT) -s
	
$(PUSH_SWAP_BONUS_A): $(PUSH_SWAP_BONUS)
	@$(MAKE) -C $(PUSH_SWAP_BONUS) -s

bonus: .depend

.depend: $(PUSH_SWAP_BONUS_A) $(LIBFT_A)
	@$(CC) $^ -o $(BONUS)
	@touch .depend

clean:
	@$(MAKE) -C $(PUSH_SWAP) fclean -s
	@$(MAKE) -C $(PUSH_SWAP_BONUS) fclean -s
	@$(MAKE) -C $(LIBFT) fclean -s
	@rm -rf .depend
	
fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)

	
re: fclean all

.PHONY: all clean fclean re bonus
