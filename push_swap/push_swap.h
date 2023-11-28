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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"

// typedef struct s_stack
// {
// 	int			content;
// 	struct s_stack	*next;
// }	t_stack;

void	print_stack(t_stack *stack_a);
void	create_list(char *args[], t_stack **stack_a, int i);
void	free_matrix(char **map);
int		check_duplicates(char *args[]);
void	free_list(t_stack **lst);

#endif