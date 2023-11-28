#include "push_swap.h"

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
