/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:23:19 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/16 18:13:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	right_fork(t_philo *philo)
{
	int	i;
	int	fork;

	if (philo->program->total_philo == 1)
		return (0);
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

int	philo_is_dying(t_philo *philo)
{
	unsigned long	timestamp;

	if (get_timestamp() > philo->last_meal + philo->program->time_to_die)
	{
		pthread_mutex_lock(philo->program->print_mutex);
		timestamp = get_timestamp() - philo->program->timestamp_start;
		printf("%ld %d died\n", timestamp, philo->index + 1);
		pthread_mutex_unlock(philo->program->print_mutex);
		return (1);
	}
	return (0);
}

int	philo_is_full(t_philo *philo)
{
	pthread_mutex_lock(philo->program->meals_mutex);
	if (philo->is_full)
		return (1);
	pthread_mutex_unlock(philo->program->meals_mutex);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!all_enough_meals(philo->philos, philo->program) && !philo_is_dying(philo)) // Check if philo is dying while thinking
	{
		if (!philo_is_full)
		{
			pthread_mutex_lock(philo->fork_mutex);
			if (philo->left_fork && right_fork(philo) && philo->status == 1)
			{
				pthread_mutex_unlock(philo->fork_mutex);
				if (!take_two_forks(philo))
					return (arg); // Check if dying while taking forks
				start_eating(philo);
				start_sleeping(philo); // Check of will die while sleeping
				start_thinking(philo); // Check if dies when starting to thing
			}
			else
				pthread_mutex_unlock(philo->fork_mutex);
		}
	}
	printf("all enough meals\n");
	return (arg);
}

void	create_threads(t_program *program)
{
	int		i;
	t_philo	*philos;
	pthread_mutex_t meals_mutex;
	pthread_mutex_t print_mutex;

	i = 0;
	philos = malloc(sizeof(t_philo) * (program->total_philo + 1));
	philos[program->total_philo].index = 0;
	philos[program->total_philo].left_fork = 0;

	pthread_mutex_init(&meals_mutex, NULL);
	pthread_mutex_init(&print_mutex, NULL);
	program->meals_mutex = &meals_mutex;
	program->print_mutex = &print_mutex;
	while (i < program->total_philo)
	{
		philos[i].fork_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i].fork_mutex, NULL);
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
	while (i < program->total_philo)
	{
		pthread_create(&philos[i].td, NULL, &routine, &philos[i]);
		i++;
	}
	i = 0;
	while (i < program->total_philo)
	{
		pthread_join(philos[i].td, NULL);
		pthread_mutex_destroy(philos[i].fork_mutex);
		free(philos[i].fork_mutex);
		i++;
		return ;
	}
	free(philos);
	pthread_mutex_destroy(&meals_mutex);
	pthread_mutex_destroy(&print_mutex);
}
