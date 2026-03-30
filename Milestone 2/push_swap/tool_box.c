/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 14:17:24 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:23:32 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_nodes_b(t_stack **stack_a, t_stack **stack_b)
{
	assign_index(stack_a);
	assign_index(stack_b);
	find_match_val(stack_a, stack_b);
	push_cost(stack_a, stack_b);
	find_cheapest(stack_b);
}

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack **stack_a)
{
	t_stack	*current;
	t_stack	*next;

	if (stack_a == NULL)
		return ;
	current = *stack_a;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack_a = NULL;
}
