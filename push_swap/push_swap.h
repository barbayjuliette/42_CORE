/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:25:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/01 18:47:06 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int	content;
	struct s_stack	*next;
	int	index;
	int	push_cost;
	bool	above_median;
	bool	cheapest;
	struct s_stack *target_node;
}	t_stack;

void	free_matrix(char **map);
int		check_duplicates(char *args[], int free);
void	free_list(t_stack **lst);
void	create_list(char *args[], t_stack **stack_a, int i, int free);
void	input_error(int free, char *args[]);
int		ft_atoi_int(const char *str, char *args[], int free);
void	check_int(char *args[], int free);
void	is_a_num(const char *str, char *args[], int free);

// Sorting
int		is_ordered(t_stack *stack_a);
void	sort_stack(t_stack *stack_a);
void	big_sort(t_stack **stack_a, t_list	**instructions);
void	tiny_sort(t_stack **stack_a, t_list	**instructions);
void	add_index_median(t_stack *node);
void	find_target(t_stack *stack_a, t_stack *stack_b);

// Tesing helpers
void	print_stack(t_stack *stack_a);
void	print_instructions(t_list *stack_a);

// Linked lists
void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*new_stack(int content);
t_stack	*stack_last_node(t_stack *lst);
t_stack	*stack_before_last_node(t_stack *lst);
int	stack_size(t_stack *lst);

// Instructions
void 	swap(t_stack **stack, t_list **instructions, char c);
void	rotate(t_stack **stack, t_list **instructions, char c);
void	reverse_rotate(t_stack **stack, t_list **instructions, char c);
void	push(t_stack **stack_a, t_stack **stack_b, t_list **inst, char c);

#endif