/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:42:37 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/15 19:10:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	valid_input(char *argv[], int argc)
{
	int	i;

	if (!(argc == 6 || argc == 5))
	{
		printf("Error\nRun as follow: ./philo num_of_philo time_to_die time_to_eat"
		"time_to_sleep [num_of_times_each_philo_must_eat]\n");
		return (0);
	}
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			printf("Error\nAll numbers must be positive\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_program program;

	if (!valid_input(argv, argc))
		return (1);
	program.total_philo = ft_atoi(argv[1]);
	program.time_to_die = ft_atoi(argv[2]);
	program.time_to_eat = ft_atoi(argv[3]);
	program.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		program.max_meals = ft_atoi(argv[5]);
	program.timestamp_start = get_timestamp();
	create_threads(&program);
	return (0);
}
