/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:29:30 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 17:30:05 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*biggest_node(t_stack *stack)
{
	int		biggest;
	t_stack	*biggest_node;

	biggest = stack->content;
	biggest_node = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->content > biggest)
		{
			biggest = stack->content;
			biggest_node = stack;
		}
		stack = stack->next;
	}
	return (biggest_node);
}

void	find_target(t_stack *stack_a, t_stack *stack_b)
{
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
			target = biggest_node(stack_b);
		stack_a->target_node = target;
		stack_a = stack_a->next;
	}
}
