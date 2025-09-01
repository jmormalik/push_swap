/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 21:54:11 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/29 21:54:11 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	verification(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;

	current = stack->head;
	while (current)
	{
		next_node = current->next;
		if (! next_node)
			break ;
		else if (current->value > next_node->value)
			return (0);
		current = next_node;
	}
	return (1);
}

static int	command(t_stack *stack_a, t_stack *stack_b, char *cmd)
{
	if (ft_strncmp(cmd, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(cmd, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		rra(stack_a);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		rrb(stack_b);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
		rrr(stack_a, stack_b);
	else if (ft_strncmp(cmd, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else
		return (ft_printf("Error\n"), 1);
	return (0);
}

static void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	*cmd;

	while (1)
	{
		cmd = get_next_line(0);
		if (!cmd)
			break ;
		if (!*cmd)
		{
			free(cmd);
			break ;
		}
		if (command(stack_a, stack_b, cmd))
		{
			free(cmd);
			get_next_line(-1);
			return ;
		}
		free(cmd);
	}
	get_next_line(-1);
	if (!stack_b->head && verification(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;

	if (ac < 2)
		return (1);
	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	convert(ac, av, &stack_a);
	if (verification(&stack_a))
		print_error(0, &stack_a);
	checker(&stack_a, &stack_b);
	free_list(&stack_a);
}
