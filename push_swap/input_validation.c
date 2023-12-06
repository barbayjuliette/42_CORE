/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:56:20 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/06 13:06:38 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char *args[], int free)
{
	int	i;
	int	j;

	i = free;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	is_a_num(const char *str, char *args[], int free)
{
	if (!ft_isdigit(str[0]))
	{
		if (!(str[0] == '-' && str[1] && ft_isdigit(str[1])))
			input_error(free, args);
	}
}

void	check_int(char *args[], int free)
{
	int	i;

	i = free;
	while (args[i])
	{
		is_a_num(args[i], args, free);
		ft_atoi_int(args[i], args, free);
		i++;
	}
}

int	ft_atoi_int(const char *str, char *args[], int free)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (sign * num > 2147483647 || sign * num < -2147483647)
		input_error(free, args);
	return (sign * num);
}

void	input_error(int free, char *args[])
{
	write(2, "Error\n", 6);
	if (!free)
		free_matrix(args);
	exit(1);
}
