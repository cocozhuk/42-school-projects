/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhu@student.42.fr <kzhu>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:15:16 by kzhu@studen       #+#    #+#             */
/*   Updated: 2026/03/24 13:18:09 by kzhu@student.42.f###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;

	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*pre;
}	t_stack;

int		is_int(char c);
int		is_space(char c);
int		is_sign_legal(char *input);
int		is_empty(char *input);
int		if_valid(char *input, t_stack **stack_a);

int		is_dup(t_stack *stack_a, int new_number);
int		append_node(t_stack **a, int value);
void	assign_index(t_stack **stack);
void	find_median(t_stack **stack, int num);

void	push(t_stack **src, t_stack **des);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	re_rotate(t_stack **stack);
void	rra(t_stack **stack);
void	rrb(t_stack **stack);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	ra(t_stack **stack);
void	rb(t_stack **stack);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack);
void	sa(t_stack **stack);
void	sb(t_stack **stack);
void	ss(t_stack **stack_a, t_stack **stack_b);

int		is_sorted(t_stack *stack);
int		stack_size(t_stack *stack);
void	sort_three(t_stack **stack);
void	sort_large(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_min(t_stack *stack);
void	find_match_val(t_stack **stack_a, t_stack **stack_b);
void	each_cost(t_stack *cur_b, int size_a, int size_b);
void	push_cost(t_stack **stack_a, t_stack **stack_b);
void	find_cheapest(t_stack **stack_b);
t_stack	*get_cheapest(t_stack *stack);
void	start_nodes_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	before_push(t_stack **stack, t_stack *top, char stack_name);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	push_swap(t_stack **stack_a, t_stack **stack_b);

void	free_mem(char **str);
void	free_stack(t_stack **stack_a);

#endif