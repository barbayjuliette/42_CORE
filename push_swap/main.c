/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/27 15:01:10 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char *args[])
{
	int i;
	int j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	create_list(char *args[], t_stack **stack_a, int i)
{
	int		num;


	if (!check_duplicates(args))
	{
		ft_printf("Error\n");
		if (i == 0)
			free_matrix(args);
		exit(1);
	}
	*stack_a = ft_new_list(ft_atoi(args[i]));
	i++;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		ft_listadd_back(stack_a, ft_new_list(num));
		i++;
	}
}

int main(int argc, char *argv[])
{

	t_stack	*stack_a;
	char	**args;

	stack_a = NULL;
	if (argc == 1)
		ft_printf("Where is the argument?\n");
	else if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		create_list(args, &stack_a, 0);
		free_matrix(args);
	}
	else 
	{
		create_list(argv, &stack_a, 1);
	}
	print_stack(stack_a);
	free_list(&stack_a);
	return (0);
}
