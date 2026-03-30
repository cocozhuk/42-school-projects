/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 14:08:51 by kzhu              #+#    #+#             */
/*   Updated: 2026/03/24 13:18:57 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (argv[i])
	{
		if (if_valid(argv[i], &stack_a) != 0)
		{
			free_stack(&stack_a);
			return (write(2, "Error\n", 6), 1);
		}
		i++;
	}
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
