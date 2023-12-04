/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliettebarbay <juliettebarbay@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:18:51 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/04 15:33:40 by juliettebar      ###   ########.fr       */
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
	else if (c == 'b')
		ft_lstadd_back(instructions, ft_lstnew("sb"));
}

void	swap_both(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	swap(stack_a, instructions, 'x');
	swap(stack_b, instructions, 'x');
	ft_lstadd_back(instructions, ft_lstnew("ss"));
}

void	rotate(t_stack **stack, t_list **instructions, char c)
{
	t_stack	*first_node;
	t_stack	*second_node;
	t_stack	*last_node;

	first_node = *stack;
	second_node = (*stack)->next;
	last_node = stack_last_node(first_node);

	first_node->next = NULL;
	last_node->next = first_node;
	*stack = second_node;
	if (c == 'a')
		ft_lstadd_back(instructions, ft_lstnew("ra"));
	else if (c == 'b')
		ft_lstadd_back(instructions, ft_lstnew("rb"));
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	rotate(stack_a, instructions, 'x');
	rotate(stack_b, instructions, 'x');
	ft_lstadd_back(instructions, ft_lstnew("rr"));
}

void	reverse_rotate(t_stack **stack, t_list **instructions, char c)
{
	t_stack	*first_node;
	t_stack	*last_node;
	t_stack	*before_last;

	first_node = *stack;
	last_node = stack_last_node(first_node);
	before_last = stack_before_last_node(first_node);

	last_node->next = first_node;
	before_last->next = NULL;
	*stack = last_node;
	if (c == 'a')
		ft_lstadd_back(instructions, ft_lstnew("rra"));
	else if (c == 'b')
		ft_lstadd_back(instructions, ft_lstnew("rrb"));
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	reverse_rotate(stack_a, instructions, 'x');
	reverse_rotate(stack_b, instructions, 'x');
	ft_lstadd_back(instructions, ft_lstnew("rrr"));
}

void	push(t_stack **stack_a, t_stack **stack_b, t_list **inst, char c)
{
	t_stack	*first_a;
	t_stack	*first_b;
	t_stack	*second_b;

	first_a = *stack_a;
	first_b = *stack_b;
	second_b = first_b->next;

	first_b->next = first_a;
	*stack_a = first_b;
	*stack_b = second_b;
	if (c == 'a')
		ft_lstadd_back(inst, ft_lstnew("pa"));
	else if (c == 'b')
		ft_lstadd_back(inst, ft_lstnew("pb"));
}
