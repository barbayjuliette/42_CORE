/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:25:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/06 12:29:40 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target_node;
}	t_stack;

// Input validation
int		check_duplicates(char *args[], int free);
void	is_a_num(const char *str, char *args[], int free);
void	check_int(char *args[], int free);
int		ft_atoi_int(const char *str, char *args[], int free);
void	input_error(int free, char *args[]);

// Init stack A
void	create_list(char *args[], t_stack **stack_a, int i, int free);
void	add_index_median(t_stack *node);
void	find_target(t_stack *stack_a, t_stack *stack_b);
void	push_cost(t_stack *stack_a);
int		get_total_cost(t_stack *stack);
void	find_cheapest(t_stack *stack);

// Move cheapest to top
void	push_cheapest(t_stack **stack_a, t_stack **stack_b, t_list	**inst);
void	both_below(t_stack **s_a, t_stack **s_b, t_list **in, t_stack *a);
void	both_above(t_stack **s_a, t_stack **s_b, t_list **in, t_stack *a);
int		set_values(int *smallest, int *biggest, int *extra_pushes, t_stack *a);

// Move B to A
void	push_target_top(t_stack **stack_a, t_stack *stack_b, t_list *inst);
t_stack	*find_smallest(t_stack *stack);
void	find_target_b(t_stack *stack_a, t_stack *stack_b);
void	put_smallest_top(t_stack **stack_a, t_list	**instructions);
t_stack	*biggest_node(t_stack *stack);

// Sorting
void	init_and_move(t_stack **stack_a, t_stack **stack_b, t_list **inst);
void	big_sort(t_stack **stack_a, t_list **instructions);
void	sort_stack(t_stack *stack_a);
void	tiny_sort(t_stack **stack_a, t_list	**instructions);
int		find_biggest(t_stack *stack_a);

// Instructions
void	swap(t_stack **stack, t_list **instructions, char c);
void	rotate(t_stack **stack, t_list **instructions, char c);
void	reverse_rotate(t_stack **stack, t_list **instructions, char c);
void	push(t_stack **stack_a, t_stack **stack_b, t_list **inst, char c);
void	swap_both(t_stack **stack_a, t_stack **stack_b, t_list **instructions);
void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_list **inst);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b, t_list **ins);

// Linked list helpers
void	free_list(t_stack **lst);
void	free_matrix(char **map);
void	free_instructions(t_list **lst);
void	print_instructions(t_list *stack_a);
int		is_ordered(t_stack *stack_a);
void	stack_add_back(t_stack **lst, t_stack *new);
t_stack	*new_stack(int content);
t_stack	*stack_last_node(t_stack *lst);
t_stack	*stack_before_last_node(t_stack *lst);
int		stack_size(t_stack *lst);

#endif
