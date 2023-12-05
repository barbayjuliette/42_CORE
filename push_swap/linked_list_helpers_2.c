/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helpers_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:10:42 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 16:11:24 by jbarbay          ###   ########.fr       */
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

void	free_instructions(t_list **lst)
{
	t_list	*next;
	t_list	*current;

	current = *lst;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	print_instructions(t_list *stack_a)
{
	while (stack_a)
	{
		ft_printf("%s\n", (stack_a->content));
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
