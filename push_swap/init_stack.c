/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:28 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 10:07:31 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_index_median(t_stack *node)
{
	int		i;
	int		median;

	i = 0;
	if (!node)
		return ;
	median = stack_size(node) / 2;
	while (node)
	{
		node->index = i;
		node->cheapest = 0;
		if (i <= median)
			node->above_median = 1;
		else
			node->above_median = 0;
		i++;
		node = node->next;
	}
}

void	find_target(t_stack *stack_a, t_stack *stack_b)
{
	int		max_index;
	long	target_num;
	t_stack	*target;
	t_stack	*b;

	while (stack_a)
	{
		b = stack_b;
		target_num = LONG_MIN;
		while (b)
		{
			if (b->content <= stack_a->content && b->content > target_num)
			{
				target_num = b->content;
				target = b;
			}
			b = b->next;
		}
		if (target_num == LONG_MIN)
		{
			max_index = find_biggest(stack_b);
			b = stack_b;
			while (b)
			{
				if (b->index == max_index)
					target = b;
				b = b->next;
			}
		}
		stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}

void	push_cost(t_stack *stack_a)
{
	int	len_a;
	// int	len_b;

	len_a = stack_size(stack_a);
	// len_b = stack_size(stack_b);
	while (stack_a)
	{
		if (stack_a->above_median)
			stack_a->push_cost = stack_a->index;
		else
			stack_a->push_cost = len_a - stack_a->index;

		// if (stack_a->target_node->above_median)
		// 	stack_a->push_cost = stack_a->target_node->index;
		// else
		// 	stack_a->push_cost += len_b - stack_a->target_node->index;
		stack_a = stack_a->next;
	}
}

int	get_total_cost(t_stack *stack)
{
		int	cost_a;
		int	cost_b;

		cost_a = stack->push_cost;
		cost_b = stack->target_node->push_cost;

		if (stack->above_median == stack->target_node->above_median)
		{
			if (cost_a > cost_b)
				return (cost_a);
			else
				return (cost_b);
		}
		return (cost_a + cost_b);
}

void	find_cheapest(t_stack *stack)
{
	int	current_cost;
	long	cheapest_cost;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_cost = LONG_MAX;
	while (stack)
	{
		current_cost = get_total_cost(stack);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
