/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:17:49 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/26 14:27:13 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}t_node;

typedef struct s_stack
{
	int			size;
	t_node		*head;
	t_node		*tail;
}t_stack;

char	**ps_split(char const *s, char c, t_stack *stack);
int		ps_atoi(const char *nptr, t_stack *stack);
void	print_error(int i, t_stack *stack);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	rr(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	rrr(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	ss(t_stack *a, t_stack *b);
t_node	*node_make(char *splited, t_stack *stack);
void	verification(t_stack *stack);
void	sort(t_stack *stack);
void	convert(int ac, char **av);
void	free_stack(t_stack *stack);
void	free_split(char **splited);

t_node	*new_node(int new_data);
void	add_node(t_stack *stack, t_node *new, char **splited);

#endif

