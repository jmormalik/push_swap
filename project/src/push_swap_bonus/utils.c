/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:08:14 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/21 16:08:14 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_stack(t_stack *stack)
{
	t_node		*head;
	t_node		*tmp;

	if (!stack)
		return ;
	head = stack->head;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

int	ps_atoi(const char *nptr, t_stack *stack)
{
	long long	value;
	int			sign;

	sign = 1;
	value = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		value = value * 10 + (*nptr - '0');
		if (value > INT32_MAX || value < INT32_MIN)
			print_error(1, stack);
		nptr++;
	}
	return ((int)(value * sign));
}

void	print_error(int i, t_stack *stack)
{
	if (i > 0)
		ft_putstr_fd("Error\n", 2);
	free_stack(stack);
	exit(1);
}

t_node	*new_node(int new_data)
{
	t_node		*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = new_data;
	new_node->rank = 1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	free_split(char **splited)
{
	int		i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}
