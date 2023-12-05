/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 15:25:52 by jbarbay          ###   ########.fr       */
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

void	print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		// ft_printf("Node: %d, Index: %d, Above median: %d\n", (stack_a->content), (stack_a->index), (stack_a->above_median));
		ft_printf("Node: %d ", stack_a->content);
		ft_printf("Index: %d ", stack_a->index);
		ft_printf("Above median: %d ", stack_a->above_median);
		ft_printf("target node value: %d ", (stack_a->target_node->content));
		ft_printf("push cost: %d ",(stack_a->push_cost));
		ft_printf("cheapest: %d ",(stack_a->cheapest));
		ft_printf("\n");
		stack_a = stack_a->next;
	}
}

void	print_stack_b(t_stack *stack_a)
{
	while (stack_a)
	{
		// ft_printf("Node: %d, Index: %d, Above median: %d\n", (stack_a->content), (stack_a->index), (stack_a->above_median));
		ft_printf("Node: %d ", stack_a->content);
		ft_printf("Index: %d ", stack_a->index);
		ft_printf("Above median: %d ", stack_a->above_median);
		ft_printf("push cost: %d ",(stack_a->push_cost));
		ft_printf("\n");
		stack_a = stack_a->next;
	}
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

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		// (*lst)->previous = NULL;
	}
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		// new->previous = temp;
		new->next = NULL;
	}
}

t_stack	*new_stack(int content)
{
	t_stack	*new_list;

	new_list = (t_stack *)malloc(sizeof(t_stack));
	if (!new_list)
		return (NULL);
	// new_list->previous = NULL;
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

t_stack	*stack_last_node(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*stack_before_last_node(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

int	stack_size(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
