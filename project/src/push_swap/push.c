/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 21:28:32 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/20 21:28:32 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *a, t_stack *b)
{
	t_node	*move_node;

	if (b->head == NULL)
		return ;
	move_node = b->head;
	b->head = move_node->next;
	if (b->head)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	if (a->head == NULL)
	{
		a->head = move_node;
		a->tail = move_node;
		move_node->prev = NULL;
		move_node->next = NULL;
	}
	else
	{
		move_node->next = a->head;
		a->head->prev = move_node;
		a->head = move_node;
		move_node->prev = NULL;
	}
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pb\n");
}