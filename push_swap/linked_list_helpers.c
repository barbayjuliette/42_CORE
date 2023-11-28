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