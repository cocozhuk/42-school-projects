/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:56:54 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:27:15 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	sort_three(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (!stack || !*stack)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	if ((first->value > second->value) && (first->value > third->value))
		ra(stack);
	else if (((second->value > first->value) && (second->value > third->value)))
		rra(stack);
	if (is_sorted(*stack) == 1)
		sa(stack);
}

void	sort_large(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	t_stack	*min_node;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	size_a = stack_size(*stack_a);
	while (size_a > 3)
	{
		pb(stack_a, stack_b);
		size_a--;
	}
	sort_three(stack_a);
	while (*stack_b != NULL)
	{
		start_nodes_b(stack_a, stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	assign_index(stack_a);
	min_node = find_min(*stack_a);
	before_push(stack_a, min_node, 'a');
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_a;

	if (!stack_a || !*stack_a || !stack_b)
		return ;
	if (is_sorted(*stack_a) == 0)
		return ;
	size_a = stack_size(*stack_a);
	if (size_a == 2)
		sa(stack_a);
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a > 3)
		sort_large(stack_a, stack_b);
}
