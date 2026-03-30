/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_push_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0026/03/23 19:14:15 by hu@student        #+#    #+#             */
/*   Updated: 2026/03/24 13:29:44 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack != NULL)
	{
		if (stack->cheapest == 1)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rr(a, b);
	assign_index(a);
	assign_index(b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b);
	assign_index(a);
	assign_index(b);
}

void	before_push(t_stack **stack, t_stack *top, char stack_name)
{
	while (*stack != top)
	{
		if (stack_name == 'a')
		{
			if (top->above_median == 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median == 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*stack_b);
	if (cheapest_node->above_median == 1
		&& cheapest_node->target_node->above_median == 1)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (cheapest_node->above_median == -1
		&& cheapest_node->target_node->above_median == -1)
		rev_rotate_both(stack_a, stack_b, cheapest_node);
	before_push(stack_a, cheapest_node->target_node, 'a');
	before_push(stack_b, cheapest_node, 'b');
	pa(stack_a, stack_b);
}
