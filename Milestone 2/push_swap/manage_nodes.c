/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0026/03/14 16:23:04 by hu@student        #+#    #+#             */
/*   Updated: 2026/03/24 13:24:34 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_median(t_stack **stack, int num)
{
	t_stack	*current;
	int		median;

	if (!stack || !*stack)
		return ;
	current = *stack;
	median = num / 2;
	while (current != NULL)
	{
		if (current->index <= median)
			current->above_median = 1;
		else
			current->above_median = -1;
		current = current->next;
	}
}

void	assign_index(t_stack **stack)
{
	int		i;
	t_stack	*current;

	if (!stack || !*stack)
		return ;
	i = 0;
	current = *stack;
	while (current != NULL)
	{
		current->index = i;
		i++;
		current = current->next;
	}
	find_median(stack, i);
}

int	is_dup(t_stack *stack_a, int new_number)
{
	while (stack_a != NULL)
	{
		if (stack_a->value == new_number)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	append_node(t_stack **stack_a, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (1);
	ft_memset(new_node, 0, sizeof(t_stack));
	new_node->value = value;
	new_node->index = -1;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		return (0);
	}
	last_node = *stack_a;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->pre = last_node;
	return (0);
}
