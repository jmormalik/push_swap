/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 14:59:26 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/19 14:59:26 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack->head || !stack->head->next)
		return ;
	first = stack->head;
	second = first->next;
	if (second->next)
	{
		second->next->prev = first;
		first->next = second->next;
	}
	else
	{
		stack->tail = first;
		first->next = NULL;
	}
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	stack->head = second;
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}

void	sa(t_stack *a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	swap(b);
	ft_printf("sb\n");
}
