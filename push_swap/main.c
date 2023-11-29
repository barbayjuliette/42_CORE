/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/29 16:57:49 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_list(char *args[], t_stack **stack_a, int i, int free)
{
	int		num;

	check_int(args, free);
	if (!check_duplicates(args))
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

// void	big_sort(t_stack **stack_a, t_list	**instructions)
// {
// 	t_stack	*stack_b;

// 	stack_b = 0;
// 	if (ft_lstsize(stack_a) > 3)
// 		push(&stack_b, stack_a, instructions, 'b');
// 	if (ft_lstsize(stack_a) > 3)
// 		push(&stack_b, stack_a, instructions, 'b');
// 	while ((ft_lstsize(stack_a) > 3))
// 	{

// 	}
// 	tiny_sort(stack_a, instructions);
// 	while (ft_lstsize(stack_b) > 0)
// 		push(stack_a, &stack_b, instructions, 'a');

// }

void	sort_stack(t_stack *stack_a)
{
	int	size;
	t_list	*instructions;

	instructions = NULL;
	size = ft_lstsize(stack_a);
	if (is_ordered(stack_a))
		ft_printf("\n");
	else if (size == 2)
		swap(&stack_a, &instructions, 'a');
	else if (size == 3)
		tiny_sort(&stack_a, &instructions);
	// else
	// 	big_sort(&stack_a, &instructions);
	ft_printf("New stack after swapping:\n");
	print_stack(stack_a);
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
	print_stack(stack_a);
	ft_printf("\n");
	sort_stack(stack_a);
	free_list(&stack_a);
	return (0);
}
