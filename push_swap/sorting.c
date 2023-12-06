/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:11 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/06 15:39:33 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_and_move(t_stack **stack_a, t_stack **stack_b, t_list **inst)
{
	add_index_median(*stack_a);
	add_index_median(*stack_b);
	find_target(*stack_a, *stack_b);
	push_cost(*stack_a);
	push_cost(*stack_b);
	find_cheapest(*stack_a);
	push_cheapest(stack_a, stack_b, inst);
	push(stack_b, stack_a, inst, 'b');
}

void	big_sort(t_stack **stack_a, t_list **instructions)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_size(*stack_a) > 3)
		push(&stack_b, stack_a, instructions, 'b');
	if (stack_size(*stack_a) > 3)
		push(&stack_b, stack_a, instructions, 'b');
	while ((stack_size(*stack_a) > 3))
		init_and_move(stack_a, &stack_b, instructions);
	tiny_sort(stack_a, instructions);
	while ((stack_size(stack_b) > 0))
	{
		add_index_median(*stack_a);
		add_index_median(stack_b);
		find_target_b(*stack_a, stack_b);
		push_target_top(stack_a, stack_b, *instructions);
		push(stack_a, &stack_b, instructions, 'a');
	}
	put_smallest_top(stack_a, instructions);
	free_list(stack_a);
	end_program(stack_a, instructions);
}

void	sort_stack(t_stack *stack_a)
{
	int		size;
	t_list	*instructions;

	instructions = NULL;
	size = stack_size(stack_a);
	if (is_ordered(stack_a))
	{
		end_program(&stack_a, &instructions);
		return ;
	}
	else if (size == 2)
		swap(&stack_a, &instructions, 'a');
	else if (size == 3)
		tiny_sort(&stack_a, &instructions);
	else
		big_sort(&stack_a, &instructions);
	end_program(&stack_a, &instructions);
}

void	tiny_sort(t_stack **stack_a, t_list	**instructions)
{
	int	biggest;

	biggest = find_biggest(*stack_a);
	if (biggest == 0)
		rotate(stack_a, instructions, 'a');
	else if (biggest == 1)
		reverse_rotate(stack_a, instructions, 'a');
	if (!is_ordered(*stack_a))
		swap(stack_a, instructions, 'a');
}

int	find_biggest(t_stack *stack_a)
{
	int	max;
	int	pos;
	int	i;

	max = stack_a->content;
	i = 1;
	pos = 0;
	stack_a = stack_a->next;
	while (stack_a)
	{
		if (stack_a->content > max)
		{
			max = stack_a->content;
			pos = i;
		}
		i++;
		stack_a = stack_a->next;
	}
	return (pos);
}
