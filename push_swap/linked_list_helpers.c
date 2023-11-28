/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/28 15:59:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack **lst)
{
	t_stack	*next;
	t_stack	*current;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("Node: %d\n", (stack_a->content));
		stack_a = stack_a->next;
	}
}

int	is_ordered(t_stack *stack_a)
{
	int	num;

	num = stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{	
		if (num > stack_a->content)
			return (0);
		num = stack_a->content;
		stack_a = stack_a->next;
	}
	return (1);
}