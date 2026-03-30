/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:19:28 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:34:21 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **src, t_stack **des)
{
	t_stack	*target;

	if (!src || !*src)
		return ;
	target = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->pre = NULL;
	target->next = *des;
	if (*des != NULL)
		(*des)->pre = target;
	*des = target;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
