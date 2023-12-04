/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliettebarbay <juliettebarbay@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:22 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/04 14:27:49 by juliettebar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	one_arg(char const *argv[], t_stack **stack_a)
{
	char	**args;
	int		i;
	int		num;

	i = 1;
	args = ft_split(argv[1], ' ');
	*stack_a = new_stack(ft_atoi(args[0]));
	while (args[i])
	{
		num = ft_atoi(args[i]);
		stack_add_back(stack_a, new_stack(num));
		i++;
	}
}

void	x_arg(char const *argv[], t_stack **stack_a, int argc)
{
	int		i;
	int		num;

	i = 1;
	*stack_a = new_stack(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		stack_add_back(stack_a, new_stack(num));
		i++;
	}
}

// int	get_cost(t_stack *stack)
// {
// 	int	length;

// 	length = stack_size(stack);
// 	if (stack->above_median)
// 			stack->push_cost = stack->index;
// 	else
// 		stack->push_cost = length - stack->index;
// }

// void	set_push_cost(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	cost_a;
// 	int	cost_b;
// 	int	smallest;
// 	int	biggest;

// 	while (stack_a)
// 	{
// 		cost_a = get_cost(stack_a);
// 		cost_b = get_cost(stack_b);

// 		if (stack_a->above_median == stack_b->above_median)
// 		{
// 			if (cost_a > cost_b)
// 				stack_a->push_cost = cost_a;
// 			else
// 				stack_a->push_cost = cost_b;
// 		}
// 		stack_a->push_cost = cost_a + cost_b;
// 	}
// }
