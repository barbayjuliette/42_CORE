/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:17:13 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/06 12:27:03 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_values(int *smallest, int *biggest, int *extra_pushes, t_stack *a)
{
	if (a->push_cost > a->target_node->push_cost)
	{
		*smallest = a->target_node->push_cost;
		*biggest = a->push_cost;
		*extra_pushes = 1;
	}
	else
	{
		*biggest = a->target_node->push_cost;
		*smallest = a->push_cost;
		*extra_pushes = 2;
	}
	if (a->push_cost == a->target_node->push_cost)
		*extra_pushes = 2;
	return (*smallest);
}

void	both_above(t_stack **s_a, t_stack **s_b, t_list **in, t_stack *a)
{
	int		smallest;
	int		biggest;
	int		extra_pushes;
	int		i;

	i = set_values(&smallest, &biggest, &extra_pushes, a);
	while (i)
	{
		rotate_both(s_a, s_b, in);
		i--;
	}
	i = biggest - smallest;
	while (i)
	{
		if (extra_pushes == 1)
			rotate(s_a, in, 'a');
		else if (extra_pushes == 2)
			rotate(s_b, in, 'b');
		i--;
	}
}

void	both_below(t_stack **s_a, t_stack **s_b, t_list **in, t_stack *a)
{
	int		smallest;
	int		biggest;
	int		extra_pushes;
	int		i;

	i = set_values(&smallest, &biggest, &extra_pushes, a);
	while (i)
	{
		reverse_rotate_both(s_a, s_b, in);
		i--;
	}
	i = biggest - smallest;
	while (i)
	{
		if (extra_pushes == 1)
			reverse_rotate(s_a, in, 'a');
		else if (extra_pushes == 2)
			reverse_rotate(s_b, in, 'b');
		i--;
	}
}

void	push_cheapest(t_stack **stack_a, t_stack **stack_b, t_list	**inst)
{
	t_stack	*a;

	a = *stack_a;
	while (a->cheapest == 0)
		a = a->next;
	if (a->above_median == 1 && a->target_node->above_median == 1)
		both_above(stack_a, stack_b, inst, a);
	else if (a->above_median == 0 && a->target_node->above_median == 0)
		both_below(stack_a, stack_b, inst, a);
	else if (a->above_median == 1)
	{
		while ((*stack_a) != a)
			rotate(stack_a, inst, 'a');
		while ((*stack_b) != a->target_node)
			reverse_rotate(stack_b, inst, 'b');
	}
	else
	{
		while ((*stack_a) != a)
			reverse_rotate(stack_a, inst, 'a');
		while ((*stack_b) != a->target_node)
			rotate(stack_b, inst, 'b');
	}
}
