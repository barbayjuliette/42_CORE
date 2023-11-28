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

// t_stack	*ft_new_list(int content)
// {
// 	t_stack	*new_list;

// 	new_list = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new_list)
// 		return (NULL);
// 	new_list->content = content;
// 	new_list->next = NULL;
// 	return (new_list);
// }

// void	ft_listadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*temp;

// 	temp = *lst;
// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		while (temp->next)
// 			temp = temp->next;
// 		temp->next = new;
// 		new->next = NULL;
// 	}
// }

void	print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		ft_printf("Node: %d\n", (stack_a->content));
		stack_a = stack_a->next;
	}
}

void	one_arg(char const *argv[], t_stack **stack_a)
{
	char	**args;
	int		i;
	int		num;

	i = 1;
	args = ft_split(argv[1], ' ');
	*stack_a = ft_new_list(ft_atoi(args[0]));
	while (args[i])
	{
		num = ft_atoi(args[i]);
		ft_listadd_back(stack_a, ft_new_list(num));
		i++;
	}
}

void	x_arg(char const *argv[], t_stack **stack_a, int argc)
{
	int		i;
	int		num;

	i = 1;
	*stack_a = ft_new_list(ft_atoi(argv[i]));
	i++;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		ft_listadd_back(stack_a, ft_new_list(num));
		i++;
	}
}

int main(int argc, char const *argv[])
{

	t_stack	*stack_a;

	stack_a = NULL;
	if (argc == 1)
		ft_printf("Where is the argument?\n");
	else if (argc == 2)
		one_arg(argv, &stack_a);
	else 
		x_arg(argv, &stack_a, argc);
	print_stack(stack_a);
	return (0);
}
