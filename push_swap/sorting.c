/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:07:11 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 11:44:35 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stack **stack_a, t_list	**instructions)
{
	t_stack	*stack_b;
	int	i;

	stack_b = NULL;
	if (stack_size(*stack_a) > 3)
		push(&stack_b, stack_a, instructions, 'b');
	if (stack_size(*stack_a) > 3)
		push(&stack_b, stack_a, instructions, 'b');
	// push(&stack_b, stack_a, instructions, 'b');
	// push(&stack_b, stack_a, instructions, 'b');
	i = 2;
	while ((stack_size(*stack_a) > 3))
	{
		add_index_median(*stack_a);
		add_index_median(stack_b);
		find_target(*stack_a, stack_b);
		push_cost(*stack_a);
		push_cost(stack_b);
		find_cheapest(*stack_a);
		ft_printf("NUM %d: ", i);
		ft_printf("\nSTACK A:\n");
		print_stack(*stack_a);
		ft_printf("\nSTACK B:\n");
		print_stack_b(stack_b);
		ft_printf("\n");
		push_cheapest(stack_a, &stack_b, instructions);
		push(&stack_b, stack_a, instructions, 'b');
		i++;
	}

	ft_printf("\n");
	ft_printf("\nSTACK A:\n");
	print_stack(*stack_a);
	ft_printf("\nSTACK B:\n");
	print_stack_b(stack_b);
	print_instructions(*instructions);
	// ft_printf("\nSTACK A:\n");
	// ft_printf("\nSTACK B:\n");
	return ;

	// while ((stack_size(stack_a) > 3))
	// {
	// 	find_target(stack_a, stack_b);
	// }
	// tiny_sort(stack_a, instructions);
	// while (stack_size(stack_b) > 0)
	// 	push(stack_a, &stack_b, instructions, 'a');

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
