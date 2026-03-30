/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:13:01 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:33:34 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	re_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second_last;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	second_last = last->pre;
	last->next = first;
	last->pre = NULL;
	first->pre = last;
	second_last->next = NULL;
	*stack = last;
}

void	rra(t_stack **stack)
{
	re_rotate(stack);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack)
{
	re_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	re_rotate(stack_a);
	re_rotate(stack_b);
	write(1, "rrr\n", 4);
}
