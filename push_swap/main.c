/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 12:46:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(char *args[], t_stack **stack_a, int i, int free)
{
	int		num;

	check_int(args, free);
	if (!check_duplicates(args, free))
		input_error(free, args);
	num = ft_atoi(args[i]);
	*stack_a = new_stack(num);
	i++;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		stack_add_back(stack_a, new_stack(num));
		i++;
	}
}

void	push_cheapest(t_stack **stack_a, t_stack **stack_b, t_list	**instructions)
{
	int		smallest;
	int		biggest;
	char	extra_pushes;
	int		i;
	t_stack	*a;
	// t_stack	*b;

	a = *stack_a;
	// b = *stack_b;
	while (a->cheapest == 0)
		a = a->next;
// OPTION 1: Both above median
	if (a->above_median == 1 && a->target_node->above_median == 1)
	{
		// ft_printf("Both above median\n");
		if (a->push_cost > a->target_node->push_cost)
		{
			smallest = a->target_node->push_cost;
			biggest = a->push_cost;
			extra_pushes = 'a';
		}
		else
		{
			biggest = a->target_node->push_cost;
			smallest = a->push_cost;
			extra_pushes = 'b';
		}
		if (a->push_cost == a->target_node->push_cost)
			extra_pushes = 'b';
		i = smallest;
		while (i)
		{
			rotate_both(stack_a, stack_b, instructions);
			// ft_printf("i: %d\n", i);
			i--;
		}
		i = biggest - smallest;
		while (i)
		{
			if (extra_pushes == 'a')
				rotate(stack_a, instructions, 'a');
			else if (extra_pushes == 'b')
				rotate(stack_b, instructions, 'b');
			i--;
		}
	}
	// OPTION 2: BOTH NOT ABOVE MEDIAN
	else if (a->above_median == 0 && a->target_node->above_median == 0)
	{
		// ft_printf("Both below median\n");
		if (a->push_cost > a->target_node->push_cost)
		{
			smallest = a->target_node->push_cost;
			biggest = a->push_cost;
			extra_pushes = 'a';
		}
		else
		{
			biggest = a->target_node->push_cost;
			smallest = a->push_cost;
			extra_pushes = 'b';
		}
		if (a->push_cost == a->target_node->push_cost)
			extra_pushes = 'b';
		i = smallest;
		while (i)
		{
			reverse_rotate_both(stack_a, stack_b, instructions);
			i--;
		}
		i = biggest - smallest;
		while (i)
		{
			if (extra_pushes == 'a')
				reverse_rotate(stack_a, instructions, 'a');
			else if (extra_pushes == 'b')
				reverse_rotate(stack_b, instructions, 'b');
			i--;
		}
	}

	// OPTION 3: ONE ABOVE ONE BELOW
	else if (a->above_median == 1)
	{
		// ft_printf("One below, one above median\n");
		// a above median and b below
		while ((*stack_a) != a)
			rotate(stack_a, instructions, 'a');
		while ((*stack_b) != a->target_node)
			reverse_rotate(stack_b, instructions, 'b');
	}
	else
	{
		while ((*stack_a) != a)
			reverse_rotate(stack_a, instructions, 'a');
		while ((*stack_b) != a->target_node)
			rotate(stack_b, instructions, 'b');
	}
}

int main(int argc, char *argv[])
{

	t_stack	*stack_a;
	char	**args;

	stack_a = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		create_list(args, &stack_a, 0, 0);
		free_matrix(args);
	}
	else
	{
		create_list(argv, &stack_a, 1, 1);
	}
	// print_stack(stack_a);
	// ft_printf("\n");
	sort_stack(stack_a);
	free_list(&stack_a);
	return (0);
}
