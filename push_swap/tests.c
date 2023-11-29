/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:22 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/29 16:54:06 by jbarbay          ###   ########.fr       */
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
