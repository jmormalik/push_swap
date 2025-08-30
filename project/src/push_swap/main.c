/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:17:02 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/30 15:38:38 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	verification(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	print_error(0, stack);
	return (1);
}

int	main(int ac, char **av)
{
	int		size;
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	if (ac < 2)
		return (1);
	size = convert(ac, av, &stack_a);
	if (verification(&stack_a))
		return (1);
	if (size == 2)
		sort_2(&stack_a);
	else if (size == 3)
		sort_3(&stack_a);
	else if (size == 4)
		sort_4(&stack_a, &stack_b);
	else if (size == 5)
		sort_5(&stack_a, &stack_b);
	else
		sort(&stack_a, &stack_b, size);
	free_list(&stack_a);
}
