/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 00:08:40 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/27 00:08:40 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sort_2(t_stack *stack_a)
{
	sa(stack_a);
}

void	sort_3(t_stack *stack_a)
{
	if (stack_a->head->rank < stack_a->head->next->rank && \
		stack_a->head->rank < stack_a->tail->rank)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->head->rank > stack_a->head->next->rank && \
		stack_a->head->rank > stack_a->tail->rank)
	{
		if (stack_a->head->next->rank < stack_a->tail->rank)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
	else
	{
		if (stack_a->head->next->rank < stack_a->tail->rank)
			sa(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->tail->rank == 1)
		rra(stack_a);
	else
		while (stack_a->head->rank != 1)
			ra(stack_a);
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_stack *stack_a, t_stack *stack_b)
{
	int		count;

	count = 0;
	while ((!count && (stack_a->tail->rank <= 2 || \
				stack_a->tail->prev->rank <= 2)) || \
		(count == 1 && stack_a->tail->rank <= 2))
	{
		count++;
		while (stack_a->head->rank > 2)
			rra(stack_a);
		pb(stack_a, stack_b);
	}
	while (count != 2)
	{
		count++;
		while (stack_a->head->rank > 2)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	if (stack_b->head->rank < stack_b->tail->rank)
		sb(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
