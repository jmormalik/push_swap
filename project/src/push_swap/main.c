/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:17:02 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/26 14:02:28 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node(t_stack *stack, t_node *new, char **splited)
{
	t_node	*cur;

	cur = stack->head;
	if (cur)
	{
		while (cur)
		{
			if (cur->value > new->value)
				cur->rank += 1;
			else if (cur->value < new->value)
				new->rank += 1;
			else
			{
				free_split(splited);
				print_error(1, stack);
			}
			if (!cur->next)
				break;
			cur = cur->next;
		}
		cur->next = new;
		new->prev = cur;
	}
	else
		stack->head = new;
}


int	main(int ac, char **av)
{
	if (ac < 2)
		print_error(1, NULL);
	else
		convert(ac, av);
}
