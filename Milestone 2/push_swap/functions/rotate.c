/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:42:15 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:33:16 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	first->pre = last;
	first->next = NULL;
	last->next = first;
	second->pre = NULL;
	*stack = second;
}

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
