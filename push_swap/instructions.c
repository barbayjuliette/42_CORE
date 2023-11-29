/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:51 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/29 15:46:54 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack, t_list **instructions, char c)
{
	t_stack	*first_node;
	t_stack	*second_node;

	first_node = *stack;
	second_node =(*stack)->next;

	first_node->next = second_node->next;
	second_node->next = first_node;
	*stack = second_node;
	if (c == 'a')
		ft_lstadd_back(instructions, ft_lstnew("sa"));
	else
		ft_lstadd_back(instructions, ft_lstnew("sb"));
}

void rotate(t_stack **stack, t_list **instructions, char c)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	first_node = *stack;
	second_node = (*stack)->next;
	last_node = ft_listlast(first_node);

	first_node->next = NULL;
	last_node->next = first_node;
	*stack = second_node;
	if (c == 'a')
		ft_lstadd_back(instructions, ft_lstnew("ra"));
	else
		ft_lstadd_back(instructions, ft_lstnew("rb"));
}

void	reverse_rotate(t_stack **stack, t_list **instructions, char c)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*before_last;

	first_node = *stack;
	last_node = ft_listlast(first_node);
	before_last = ft_list_before_last(first_node);

	last_node->next = first_node;
	before_last->next = NULL;
	*stack = last_node;
	if (c == 'a')
		ft_lstadd_back(instructions, ft_lstnew("rra"));
	else
		ft_lstadd_back(instructions, ft_lstnew("rrb"));
}
