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

void	push_a(t_stack *a, t_stack *b)
{
	t_node	*move_node;

	if (b->size == 0)
		return ;
	move_node = b->head;
	b->head = move_node->next;
	if (b->head)
		b->head->prev = NULL;
	else
		b->tail = NULL;
	if (b->size-- && a->size == 0)
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
	a->size++;
}
void	push_b(t_stack *a, t_stack *b)
{
	t_node	*move_node;

	if (a->size == 0)
		return ;
	move_node = a->head;
	a->head = move_node->next;
	if (a->head)
		a->head->prev = NULL;
	else
		a->tail = NULL;
	if (a->size-- && b->size == 0)
	{
		b->head = move_node;
		b->tail = move_node;
		move_node->prev = NULL;
		move_node->next = NULL;
	}
	else
	{
		move_node->next = b->head;
		b->head->prev = move_node;
		b->head = move_node;
		move_node->prev = NULL;
	}
	b->size++;
}