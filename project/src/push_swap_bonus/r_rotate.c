/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:25:54 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/20 21:25:54 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_prev;

    if (! stack->head || ! stack->head->next)
        return ;    
	first = stack->head;
	last = stack->tail;
	last_prev = last->prev;
	last->next = first;
	first->prev = last;
	last_prev->next = NULL;
	last->prev = NULL;
	stack->head = last;
	stack->tail = last_prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
}
