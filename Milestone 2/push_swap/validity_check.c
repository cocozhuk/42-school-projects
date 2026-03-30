/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validity_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 17:12:31 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:22:14 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_int(char c)
{
	if (c == ' ' || ('0' <= c && c <= '9')
		|| (c >= 9 && c <= 13) || c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	is_empty(char *input)
{
	int	i;
	int	len;
	int	spaces;

	i = 0;
	spaces = 0;
	while (input[i])
	{
		if (is_space(input[i]) == 1)
		{
			spaces++;
			input[i] = ' ';
		}
		i++;
	}
	len = ft_strlen(input);
	if (len == spaces)
		return (1);
	return (0);
}

int	is_sign_legal(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (is_int(input[i]) == 0)
			return (1);
		if (input[i] == '+' || input[i] == '-')
		{
			if (i > 0 && (is_space(input[i - 1]) == 0))
				return (1);
			if (input[i + 1] < '0' || input[i + 1] > '9')
				return (1);
		}
		i++;
	}
	return (0);
}

int	if_valid(char *input, t_stack **stack_a)
{
	int		i;
	long	temp;
	char	**nums;

	i = 0;
	if (input[0] == '\0' || is_empty(input) == 1 || is_sign_legal(input) == 1)
		return (1);
	nums = ft_split(input, ' ');
	while (nums[i])
	{
		temp = ft_atol(nums[i]);
		if (temp < INT_MIN || temp > INT_MAX)
			return (free_mem(nums), 1);
		if (is_dup(*stack_a, (int)temp) == 1)
			return (free_mem(nums), 1);
		append_node(stack_a, (int)temp);
		i++;
	}
	free_mem(nums);
	return (0);
}
