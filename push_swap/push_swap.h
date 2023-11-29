/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:25:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/11/29 15:43:14 by jbarbay          ###   ########.fr       */
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

// typedef	struct s_instructions
// {
// 	void	*content;
// 	struct s_instructions	*next;
// } t_list;

void	print_stack(t_stack *stack_a);
void	free_matrix(char **map);
int		check_duplicates(char *args[]);
void	free_list(t_stack **lst);
void	create_list(char *args[], t_stack **stack_a, int i, int free);
void	input_error(int free, char *args[]);
int		ft_atoi_int(const char *str, char *args[], int free);
void	check_int(char *args[], int free);
void	is_a_num(const char *str, char *args[], int free);
int		is_ordered(t_stack *stack_a);
void	sort_stack(t_stack *stack_a);
void	print_instructions(t_list *stack_a);

// Linked lists
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
t_stack	*ft_listlast(t_stack *lst);
t_stack	*ft_list_before_last(t_stack *lst);

// Instructions
void 	swap(t_stack **stack, t_list **instructions, char c);
void	rotate(t_stack **stack, t_list **instructions, char c);
void	reverse_rotate(t_stack **stack, t_list **instructions, char c);

#endif