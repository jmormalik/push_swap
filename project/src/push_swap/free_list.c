/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemyu <jaemyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 16:22:14 by jaemyu            #+#    #+#             */
/*   Updated: 2025/08/29 16:22:14 by jaemyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *stack)
{
	t_node		*cur;
	t_node		*next_node;

	cur = stack->head;
	while (cur)
	{
		next_node = cur->next;
		free(cur);
		cur = next_node;
	}
}
