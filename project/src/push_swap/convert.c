/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:39:04 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/26 15:58:38 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	convert(int ac, char **av)
{
	int		i;
	int		j;
	t_node	*new;
	t_stack stack;
	char	**splited;

	stack.head = NULL;
	stack.tail = NULL;
	stack.size = 0;
	i = 0;
	while (++i < ac)
	{
		splited = ps_split(av[i], ' ', &stack);
		if (!splited)
			print_error(1, &stack);
		j = 0;
		while (splited[j])
		{
			new = node_make(splited[j++], &stack);
			add_node(&stack, new, splited);
		}
		free_split(splited);
	}
	verification(&stack);
	sort(&stack);
}

void	verification(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return;
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return ;
		current = current->next;
	}
	print_error(1, stack);
}

t_node	*node_make(char *splited, t_stack *stack)
{
	t_node	*new;

	new = new_node(ps_atoi(splited, stack));
	if (!new)
		print_error(1, stack);
	return (new);
}
