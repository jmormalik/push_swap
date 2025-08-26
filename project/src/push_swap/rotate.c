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

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*last;

	if (stack->size < 3)
	{
		if (stack->size == 2)
			swap(stack);
		return ;
	}
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
	ft_printf("rr");
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*last_prev;

	if (stack->size < 3)
	{
		if (stack->size == 2)
			swap(stack);
		return ;
	}
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
	ft_printf("rrr");
}