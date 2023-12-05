/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:33 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/05 17:35:48 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_both(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	swap(stack_a, instructions, 'x');
	swap(stack_b, instructions, 'x');
	ft_lstadd_back(instructions, ft_lstnew("ss"));
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_list **instructions)
{
	rotate(stack_a, instructions, 'x');
	rotate(stack_b, instructions, 'x');
	ft_lstadd_back(instructions, ft_lstnew("rr"));
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_list **inst)
{
	reverse_rotate(stack_a, inst, 'x');
	reverse_rotate(stack_b, inst, 'x');
	ft_lstadd_back(inst, ft_lstnew("rrr"));
}
