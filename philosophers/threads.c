/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:23:19 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/15 17:59:46 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	right_fork(t_philo *philo)
{
	int	i;
	int	fork;
	
	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;
	fork = (philo->philos)[i].left_fork;

	return (fork);
}

int	all_enough_meals(t_philo *philos, t_program *program)
{
	int	i;

	i = 0;
	pthread_mutex_lock(program->meals_mutex);
	while (i < program->total_philo)
	{
		if (!philos[i].is_full)
		{
			pthread_mutex_unlock(program->meals_mutex);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(program->meals_mutex);
	return (1);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!all_enough_meals(philo->philos, philo->program))
	{
		pthread_mutex_lock(philo->fork_mutex);
		if (philo->left_fork && right_fork(philo) && philo->status == 1)
		{
			take_two_forks(philo);
			start_eating(philo);
			pthread_mutex_unlock(philo->fork_mutex);
			start_sleeping(philo);
			start_thinking(philo);
		}
		else
		{
			pthread_mutex_unlock(philo->fork_mutex);
		}
	}
	printf("all enough meals\n");
	// return ((void *) 3);
	exit(1);
	return (arg);
}

void	create_threads(t_program *program)
{
	int		i;
	void	*retval;
	t_philo	*philos;
	pthread_mutex_t meals_mutex;

	retval = 0;
	i = 0;
	philos = malloc(sizeof(t_philo) * (program->total_philo + 1));
	philos[program->total_philo].index = 0;

	pthread_mutex_init(&meals_mutex, NULL);
	program->meals_mutex = &meals_mutex;
	printf("Initializing the philos\n");
	while (i < program->total_philo)
	{
		printf("Initializing mutex\n");
		philos[i].fork_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i].fork_mutex, NULL);
		printf("Initialized mutex\n");
		philos[i].index = i;
		philos[i].status = 1;
		philos[i].left_fork = 1;
		philos[i].total_meals = 0;
		philos[i].is_full = 0;
		philos[i].last_meal = program->timestamp_start; // Change timestamp to more recent
		philos[i].program = program;
		philos[i].philos = philos;
		i++;
	}
	i = 0;
	printf("Initialized the philos\n");
	while (i < program->total_philo)
	{
		pthread_create(&philos[i].td, NULL, &routine, &philos[i]);
		i++;
	}
	printf("Created threads\n");
	i = 0;
	while (i < program->total_philo)
	{
		// pthread_join(philos[i].td, &retval);
		pthread_join(philos[i].td, NULL);
		pthread_mutex_destroy(philos[i].fork_mutex);
		free(philos[i].fork_mutex);
		i++;
	}
	free(philos);
	pthread_mutex_destroy(&meals_mutex);
}
