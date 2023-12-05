/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:01:03 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 17:17:30 by jbarbay          ###   ########.fr       */
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

int	main(int argc, char *argv[])
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
		create_list(argv, &stack_a, 1, 1);
	sort_stack(stack_a);
	return (0);
}
