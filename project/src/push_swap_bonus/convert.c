/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 16:39:04 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/29 21:55:10 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	add_node(t_stack *stack, t_node *new, char **splited)
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
				break ;
			cur = cur->next;
		}
		cur->next = new;
		new->prev = cur;
	}
	else
		stack->head = new;
}

static t_node	*node_make(char *splited, t_stack *stack)
{
	t_node	*new;

	new = new_node(ps_atoi(splited, stack));
	if (!new)
		print_error(1, stack);
	return (new);
}

void	convert(int ac, char **av, t_stack *stack)
{
	int		i;
	int		j;
	t_node	*new;
	char	**splited;

	i = 0;
	while (++i < ac)
	{
		splited = ps_split(av[i], ' ', stack);
		if (!splited)
			print_error(1, stack);
		j = 0;
		while (splited[j])
		{
			new = node_make(splited[j++], stack);
			add_node(stack, new, splited);
		}
		free_split(splited);
	}
	stack->tail = new;
}
