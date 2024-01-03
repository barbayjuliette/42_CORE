/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:11:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 16:46:27 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	initialize_philos(t_program *program, t_philo *philos)
{
	int	i;

	i = 0;
	philos[program->total_philo].index = 0;
	philos[program->total_philo].left_fork = 0;
	while (i < program->total_philo)
	{
		philos[i].fork_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i].fork_mutex, NULL);
		philos[i].index = i;
		philos[i].dead = 0;
		philos[i].left_fork = 1;
		philos[i].total_meals = 0;
		philos[i].is_full = 0;
		philos[i].last_meal = 0;
		philos[i].program = program;
		philos[i].philos = philos;
		i++;
	}
}

void	destroy_program(t_program *program, t_philo *philos)
{
	free(philos);
	pthread_mutex_destroy(program->meals_mutex);
	pthread_mutex_destroy(program->print_mutex);
	pthread_mutex_destroy(program->sim_mutex);
}

int	start_threads(t_program *program, t_philo *philos)
{
	pthread_t		th;
	int				i;

	if (pthread_create(&th, NULL, &monitor, &philos[0]) != 0)
	{
		ft_error("Failed to create thread", program, philos);
		return (0);
	}
	if (pthread_detach(th) != 0)
	{
		ft_error("Failed to detach thread", program, philos);
		return (0);
	}
	i = 0;
	while (i < program->total_philo)
	{
		if (pthread_create(&philos[i].td, NULL, &routine, &philos[i]) != 0)
		{
			ft_error("Failed to create thread", program, philos);
			return (0);
		}
		i++;
	}
	return (1);
}

int	join_threads(t_program *program, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < program->total_philo)
	{
		if (pthread_join(philos[i].td, NULL) != 0)
		{
			ft_error("Failed to join thread", program, philos);
			return (0);
		}
		pthread_mutex_destroy(philos[i].fork_mutex);
		free(philos[i].fork_mutex);
		i++;
	}
	return (1);
}

void	create_threads(t_program *program)
{
	t_philo			*philos;
	pthread_mutex_t	meals_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	sim_mutex;

	philos = malloc(sizeof(t_philo) * (program->total_philo + 1));
	pthread_mutex_init(&meals_mutex, NULL);
	pthread_mutex_init(&print_mutex, NULL);
	pthread_mutex_init(&sim_mutex, NULL);
	program->meals_mutex = &meals_mutex;
	program->print_mutex = &print_mutex;
	program->sim_mutex = &sim_mutex;
	initialize_philos(program, philos);
	if (!start_threads(program, philos))
		return ;
	if (!join_threads(program, philos))
		return ;
	destroy_program(program, philos);
}
