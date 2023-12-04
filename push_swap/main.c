/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliettebarbay <juliettebarbay@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/04 22:56:24 by juliettebar      ###   ########.fr       */
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
		ft_printf("HERE1");
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
		ft_printf("Smallest: %d\n", smallest);
		ft_printf("biggest: %d\n", biggest);
		while (i)
		{
			rotate_both(stack_a, stack_b, instructions);
			ft_printf("i: %d\n", i);
			i--;
		}
		i = biggest - smallest;
		while (i)
		{
			if (extra_pushes == 'a')
			rotate(stack_a, instructions, 'a');
			i--;
		}
	}
	// OPTION 2: BOTH NOT ABOVE MEDIAN
	if (a->above_median == 0 && a->target_node->above_median == 0)
	{
		ft_printf("HERE2");
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
			i--;
		}
	}

	// OPTION 3: ONE ABOVE ONE BELOW
	if (a->above_median == 1)
	{
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
		ft_printf("HERE\n");
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
	push(&stack_b, stack_a, instructions, 'b');
	push(&stack_b, stack_a, instructions, 'b');

	add_index_median(*stack_a);
	add_index_median(stack_b);
	print_stack_b(stack_b);
	ft_printf("\n");
	find_target(*stack_a, stack_b);
	push_cost(*stack_a);
	push_cost(stack_b);
	find_cheapest(*stack_a);
	push_cheapest(stack_a, &stack_b, instructions);
	ft_printf("\nSTACK A:\n");
	print_stack(*stack_a);
	ft_printf("\nSTACK B:\n");
	print_stack_b(stack_b);
	print_instructions(*instructions);
	// ft_printf("\nSTACK A:\n");
	// ft_printf("\nSTACK B:\n");
	// print_stack(stack_b);
	// print_stack(stack_b);
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
