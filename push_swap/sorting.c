/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:11 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 15:18:29 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_target_top(t_stack **stack_a, t_stack *stack_b, t_list *instructions)
{
	if (stack_b->target_node->above_median == 1)
	{
		while ((*stack_a)->content != stack_b->target_node->content)
			rotate(stack_a, &instructions, 'a');
	}
	else
	{
		while ((*stack_a)->content != stack_b->target_node->content)
			reverse_rotate(stack_a, &instructions, 'a');
	}
}

t_stack	*find_smallest(t_stack *stack)
{
	int	smallest;
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
// Set it to NULL, and then check if it is NULL at the end, then use the min.
	long	target_num;
	t_stack	*target_node;
	t_stack	*a;

	a = stack_a;
	target_num = LONG_MAX;
	while (stack_a)
	{
		if (stack_a->content > stack_b->content && stack_a->content < target_num)
		{
			target_num = stack_a->content;
			target_node	= stack_a;
		}
		stack_a = stack_a->next;
	}
	if (target_num == LONG_MAX)
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

void	big_sort(t_stack **stack_a, t_list	**instructions)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (stack_size(*stack_a) > 3)
		push(&stack_b, stack_a, instructions, 'b');
	if (stack_size(*stack_a) > 3)
		push(&stack_b, stack_a, instructions, 'b');
	while ((stack_size(*stack_a) > 3))
	{
		add_index_median(*stack_a);
		add_index_median(stack_b);
		find_target(*stack_a, stack_b);
		push_cost(*stack_a);
		push_cost(stack_b);
		find_cheapest(*stack_a);
		push_cheapest(stack_a, &stack_b, instructions);
		push(&stack_b, stack_a, instructions, 'b');
	}
	tiny_sort(stack_a, instructions);

	// ft_printf("\n");
	// ft_printf("\nSTACK A:\n");
	// print_stack(*stack_a);
	// ft_printf("\nSTACK B:\n");
	// print_stack_b(stack_b);
	// print_instructions(*instructions);
	while ((stack_size(stack_b) > 0))
	{
		find_target_b(*stack_a, stack_b);
		push_target_top(stack_a, stack_b, *instructions);
		push(stack_a, &stack_b, instructions, 'a');
	}
	put_smallest_top(stack_a, instructions);
	// ft_printf("\nSTACK A:\n");
	// print_stack(*stack_a);
	print_instructions(*instructions);
	free_list(stack_a);
	free_list(&stack_b);
	free_instructions(instructions);
	return ;
}

void	sort_stack(t_stack *stack_a)
{
	int	size;
	t_list	*instructions;

	instructions = NULL;
	size = stack_size(stack_a);
	if (is_ordered(stack_a))
		ft_printf("\n");
	else if (size == 2)
		swap(&stack_a, &instructions, 'a');
	else if (size == 3)
		tiny_sort(&stack_a, &instructions);
	else
		big_sort(&stack_a, &instructions);
	// ft_printf("New stack after swapping:\n");
	// print_stack(stack_a);
}

void	tiny_sort(t_stack **stack_a, t_list	**instructions)
{
	int biggest;

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
