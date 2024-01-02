/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:23:19 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/02 16:41:36 by jbarbay          ###   ########.fr       */
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

	pthread_mutex_lock(program->sim_mutex);
	if (program->end_simulation)
	{
		pthread_mutex_unlock(program->sim_mutex);
		return (1);
	}
	pthread_mutex_unlock(program->sim_mutex);

	if (program->max_meals == -1)
		return (0);
	
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

int	end_simulation(t_program *program)
{	
	int	ret;
	pthread_mutex_lock(program->sim_mutex);
	ret = program->end_simulation;
	pthread_mutex_unlock(program->sim_mutex);
	return (ret);
}

void	*is_dying(void *arg)
{
	t_philo		*philos;
	t_program	*program;
	int			timestamp;
	int			i;

	philos = ((t_philo *)arg)->philos;
	program = ((t_philo *)arg)->program;
	while (!end_simulation(program))
	{
		i = 0;
		while (i < program->total_philo)
		{
			if (!philo_is_full(&philos[i]))
			{
				timestamp = get_timestamp() - philos[i].program->timestamp_start;
				if (timestamp - philos[i].last_meal > program->time_to_die)
				{
					pthread_mutex_lock(philos[i].program->print_mutex);
					printf("%d %d died\n", timestamp, philos[i].index + 1);
					pthread_mutex_unlock(philos[i].program->print_mutex);

					pthread_mutex_lock(philos[i].program->sim_mutex);
					philos[i].program->end_simulation = 1;
					pthread_mutex_unlock(philos[i].program->sim_mutex);
					return (arg);
				}
			}
			i++;
		}
	}
	return (arg);
}

int	philo_is_full(t_philo *philo)
{
	if (philo->program->max_meals == -1)
		return (0);
	pthread_mutex_lock(philo->program->meals_mutex);
	if (philo->is_full)
	{
		pthread_mutex_unlock(philo->program->meals_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->program->meals_mutex);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!all_enough_meals(philo->philos, philo->program))
	{
		if (!philo_is_full(philo))
		{
			pthread_mutex_lock(philo->fork_mutex);
			if (philo->left_fork && right_fork(philo) && philo->status == 1)
			{
				pthread_mutex_unlock(philo->fork_mutex);
				take_two_forks(philo);
				start_eating(philo);
				start_sleeping(philo);
				start_thinking(philo);
			}
			else
				pthread_mutex_unlock(philo->fork_mutex);
		}
	}
	// pthread_mutex_lock(philo->program->print_mutex);
	// printf("all enough meals\n");
	// pthread_mutex_unlock(philo->program->print_mutex);
	return (arg);
}

void	create_threads(t_program *program)
{
	int				i;
	t_philo			*philos;
	pthread_mutex_t meals_mutex;
	pthread_mutex_t print_mutex;
	pthread_mutex_t sim_mutex;
	pthread_t		th;

	i = 0;
	philos = malloc(sizeof(t_philo) * (program->total_philo + 1));
	philos[program->total_philo].index = 0;
	philos[program->total_philo].left_fork = 0;

	// Initialize all the values
	pthread_mutex_init(&meals_mutex, NULL);
	pthread_mutex_init(&print_mutex, NULL);
	pthread_mutex_init(&sim_mutex, NULL);
	program->meals_mutex = &meals_mutex;
	program->print_mutex = &print_mutex;
	program->sim_mutex = &sim_mutex;
	while (i < program->total_philo)
	{
		philos[i].fork_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i].fork_mutex, NULL);
		philos[i].index = i;
		philos[i].status = 1;
		philos[i].dead = 0;
		philos[i].left_fork = 1;
		philos[i].total_meals = 0;
		philos[i].is_full = 0;
		philos[i].last_meal = 0; // Change timestamp to more recent
		philos[i].program = program;
		philos[i].philos = philos;
		i++;
	}
	// Detached thread
	pthread_create(&th, NULL, &is_dying,  &philos[0]);
	pthread_detach(th);
	
	// Create threads
	i = 0;
	while (i < program->total_philo)
	{
		pthread_create(&philos[i].td, NULL, &routine, &philos[i]);
		i++;
	}
	// Join the threads
	i = 0;
	while (i < program->total_philo)
	{
		pthread_join(philos[i].td, NULL);
		pthread_mutex_destroy(philos[i].fork_mutex);
		free(philos[i].fork_mutex);
		i++;
	}
	free(philos);
	pthread_mutex_destroy(&meals_mutex);
	pthread_mutex_destroy(&print_mutex);
	pthread_mutex_destroy(&sim_mutex);
}
