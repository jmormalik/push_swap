/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 21:09:18 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/30 21:09:18 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_stack
{
	t_node		*head;
	t_node		*tail;
}t_stack;

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

char	**ps_split(char const *s, char c, t_stack *stack);
int		ps_atoi(const char *nptr, t_stack *stack);
void	print_error(int i, t_stack *stack);
void	free_stack(t_stack *stack);
void	free_split(char **splited);
t_node	*new_node(int new_data);

int		convert(int ac, char **av, t_stack *stack);

void	sort(t_stack *stack_a, t_stack *stack_b, int size);
void	sort_2(t_stack *stack_a);
void	sort_3(t_stack *stack_a);
void	sort_4(t_stack *stack_a, t_stack *stack_b);
void	sort_5(t_stack *stack_a, t_stack *stack_b);

void	free_list(t_stack *stack);

#endif