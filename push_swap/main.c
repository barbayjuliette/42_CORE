/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/29 15:41:34 by jbarbay          ###   ########.fr       */
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
	*stack_a = ft_new_list(num);
	i++;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		ft_listadd_back(stack_a, ft_new_list(num));
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
	ft_printf("Position biggest: %d\n", biggest);
	if (biggest == 0)
		rotate(stack_a, instructions, 'a');
	else if (biggest == 1)
		reverse_rotate(stack_a, instructions, 'a');
	if (!is_ordered(*stack_a))
		swap(stack_a, instructions, 'a');
}

void	sort_stack(t_stack *stack_a)
{
	int	size;
	t_list	*instructions;

	size = ft_lstsize(stack_a);
	instructions = NULL;
	if (is_ordered(stack_a))
		ft_printf("The stack is already ordered\n"); // Just display new line
	else if (size == 2) // 2 nums that are not ordered
		swap(&stack_a, &instructions, 'a');
	else if (size == 3)
		tiny_sort(&stack_a, &instructions);
	
	ft_printf("New stack after swapping:\n");
	print_stack(stack_a);

	ft_printf("List of instructions: \n");
	print_instructions(instructions);
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
	sort_stack(stack_a);
	free_list(&stack_a);
	return (0);
}
