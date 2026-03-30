/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 22:03:55 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:32:58 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	temp = second->next;
	first->next = temp;
	if (temp != NULL)
		temp->pre = first;
	second->next = first;
	first->pre = second;
	second->pre = NULL;
	*stack = second;
}

void	sa(t_stack **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
