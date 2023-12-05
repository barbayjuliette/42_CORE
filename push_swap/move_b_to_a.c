/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:53:15 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 17:53:47 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_target_top(t_stack **stack_a, t_stack *stack_b, t_list *inst)
{
	if (stack_b->target_node->above_median == 1)
	{
		while ((*stack_a)->content != stack_b->target_node->content)
			rotate(stack_a, &inst, 'a');
	}
	else
	{
		while ((*stack_a)->content != stack_b->target_node->content)
			reverse_rotate(stack_a, &inst, 'a');
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*smallest_node;

	smallest = stack->content;
	smallest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->content < smallest)
		{
			smallest = stack->content;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	find_target_b(t_stack *stack_a, t_stack *stack_b)
{
	long	num;
	t_stack	*target_node;
	t_stack	*a;

	a = stack_a;
	num = LONG_MAX;
	while (stack_a)
	{
		if (stack_a->content > stack_b->content && stack_a->content < num)
		{
			num = stack_a->content;
			target_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	if (num == LONG_MAX)
		stack_b->target_node = find_smallest(a);
	else
		stack_b->target_node = target_node;
}

void	put_smallest_top(t_stack **stack_a, t_list	**instructions)
{
	t_stack	*smallest;

	add_index_median(*stack_a);
	smallest = find_smallest(*stack_a);
	if (smallest->above_median)
	{
		while ((*stack_a)->content != smallest->content)
			rotate(&(*stack_a), instructions, 'a');
	}
	else
	{
		while ((*stack_a)->content != smallest->content)
			reverse_rotate(&(*stack_a), instructions, 'a');
	}
}
