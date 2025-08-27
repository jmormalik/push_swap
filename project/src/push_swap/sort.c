/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:40:06 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/27 18:07:39 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	btoa_sub(t_stack *stack_a, t_stack *stack_b, int size, int mode)
{
	int			flag;
	static int	flag2 = 0;

	flag = 0;
	if (flag2 && flag2-- && ++flag)
		rra(stack_a);
	while (stack_b->head->rank != size)
	{
		if (stack_b->head->rank == size - 1 && ++flag)
			pa(stack_a, stack_b);
		else if (stack_b->head->rank == size - 2 && ++flag2)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_b->head->rank < size - 2 && mode)
			rrb(stack_b);
		else if (stack_b->head->rank < size - 2 && !mode)
			rb(stack_b);
	}
	pa(stack_a, stack_b);
	if (flag)
		sa(stack_a);
	if (flag && flag2 && flag2--)
		rra(stack_a);
}

static void	sort_btoa(t_stack *stack_a, t_stack *stack_b, int size)
{
	t_node		*top;
	t_node		*bot;

	while (size > 0)
	{
		top = stack_b->head;
		bot = stack_b->tail;
		while (top->rank != size && bot->rank != size)
		{
			top = top->next;
			bot = bot->prev;
		}
		if (top->rank == size)
			btoa_sub(stack_a, stack_b, size, 0);
		else if (bot->rank == size)
			btoa_sub(stack_a, stack_b, size, 1);
		bot = bot->prev;
		size = stack_a->head->rank - 1;
	}
}

static int atob_sub(t_stack *stack_a, int rank, int mid, int mode)
{
	while(stack_a->head->rank != rank)
	{
		if (!mode)
			ra(stack_a);
		else
			rra(stack_a);
	}
	if (rank <= mid)
		return (1);
	return (0);
}

static void	sort_atob(t_stack *stack_a, t_stack *stack_b, int min, int max)
{
	int		check;
	int		repeat;
	t_node	*top;
	t_node	*bot;

	repeat = (max - min) + 1;
	while (repeat-- > 0)
	{
		top = stack_a->head;
		bot = stack_a->tail;
		check = 0;
		while (!(top->rank >= min && top->rank <= max) && \
				!(bot->rank >= min && bot->rank <= max))
		{
			top = top->next;
			bot = bot->prev;
		}
		if (top->rank >= min && top->rank <= max)
			check = atob_sub(stack_a, top->rank, (max + min) / 2, 0);
		else if (bot->rank >= min && bot->rank <= max)
			check = atob_sub(stack_a, bot->rank, (max + min) / 2, 1);
		pb(stack_a, stack_b);
		if (check)
			rb(stack_b);
	}
}


void	sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int			i;
	int			basket;
	int			range;

	basket = size / 100 + 3;
	i = 0; 
	range = (size / basket);
	while(i < basket)
	{
		sort_atob(stack_a, stack_b, i * range + 1, (i + 1) * range);
		i++;
	}
	sort_atob(stack_a, stack_b, basket * range + 1, size);
	sort_btoa(stack_a, stack_b, size);
}
