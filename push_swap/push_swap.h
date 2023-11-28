/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:25:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/27 15:25:10 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

typedef struct s_stack
{
	int			content;
	struct s_stack	*next;
}	t_stack;

void	print_stack(t_stack *stack_a);
void	ft_listadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_new_list(int content);
void	one_arg(char const *argv[], t_stack **stack_a);
void	x_arg(char const *argv[], t_stack **stack_a, int argc);