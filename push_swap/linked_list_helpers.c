/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:59:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/29 15:25:56 by jbarbay          ###   ########.fr       */
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

void	print_instructions(t_list *stack_a)
{
	while (stack_a)
	{
		ft_printf("Node: %s\n", (stack_a->content));
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

t_stack	*ft_listlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_list_before_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}