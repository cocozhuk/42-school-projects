/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:48:49 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:29:00 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cheapest(t_stack **stack_b)
{
	t_stack		*cur_b;
	t_stack		*cheap;
	long int	cheapest;

	if (!stack_b || !*stack_b)
		return ;
	cur_b = *stack_b;
	cheapest = LONG_MAX;
	while (cur_b != NULL)
	{
		if (cur_b->push_cost < cheapest)
		{
			cheapest = cur_b->push_cost;
			cheap = cur_b;
		}
		cur_b = cur_b->next;
	}
	cheap->cheapest = 1;
}

void	each_cost(t_stack *cur_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	if (cur_b->above_median == 1)
		cost_b = cur_b->index;
	else
		cost_b = size_b - (cur_b->index);
	if (cur_b->target_node->above_median == 1)
		cost_a = cur_b->target_node->index;
	else
		cost_a = size_a - (cur_b->target_node->index);
	if (cur_b->above_median == cur_b->target_node->above_median)
	{
		if (cost_a > cost_b)
			cur_b->push_cost = cost_a;
		else
			cur_b->push_cost = cost_b;
	}
	else
		cur_b->push_cost = cost_a + cost_b;
}

void	push_cost(t_stack **stack_a, t_stack **stack_b)
{
	int		size_a;
	int		size_b;
	t_stack	*cur_b;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	size_a = stack_size(*stack_a);
	size_b = stack_size(*stack_b);
	cur_b = *stack_b;
	while (cur_b != NULL)
	{
		each_cost(cur_b, size_a, size_b);
		cur_b = cur_b->next;
	}
}

t_stack	*find_min(t_stack *stack)
{
	t_stack		*cur;
	t_stack		*target;
	long int	min;

	if (!stack)
		return (NULL);
	cur = stack;
	min = LONG_MAX;
	target = NULL;
	while (cur != NULL)
	{
		if (cur->value < min)
		{
			min = cur->value;
			target = cur;
		}
		cur = cur->next;
	}
	return (target);
}

void	find_match_val(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cur_a;
	t_stack	*cur_b;
	long	best_match;

	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	cur_b = *stack_b;
	while (cur_b != NULL)
	{
		best_match = LONG_MAX;
		cur_a = *stack_a;
		while (cur_a != NULL)
		{
			if ((cur_b->value < cur_a->value) && (cur_a->value < best_match))
			{
				best_match = cur_a->value;
				cur_b->target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match == LONG_MAX)
			cur_b->target_node = find_min(*stack_a);
		cur_b = cur_b->next;
	}
}
