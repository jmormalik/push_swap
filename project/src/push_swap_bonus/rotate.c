/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:25:54 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/20 21:25:54 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (! stack->head || ! stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	last = stack->tail;
	last->next = first;
	first->prev = last;
	second->prev = NULL;
	first->next = NULL;
	stack->head = second;
	stack->tail = first;
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	ra(t_stack *a)
{
	rotate(a);
}

void	rb(t_stack *b)
{
	rotate(b);
}
