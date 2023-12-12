/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:23:19 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/12 13:15:41 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	right_fork(t_philo *philo)
{
	int	i;
	int	fork;
	
	i = (philo->num) - 1;
	if (i == 0)
		i = philo->program->total_philo;
	fork = (philo->philos)[i].left_fork;
	return (fork);
}

void	take_two_forks(t_philo *philo)
{
	int	i;
	
	i = (philo->num) - 1;
	if (i == 0)
		i = philo->program->total_philo;
	(philo->philos)[i].left_fork = 0;
	philo->left_fork = 0;
	printf("Philo %d picked up 2 forks\n", philo->num);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->program->mutex);
	if (philo->left_fork && right_fork(philo) && philo->status == 1)
	{
		// printf("Philo %d is eating\n", philo->num);
		take_two_forks(philo);
	}
	pthread_mutex_unlock(philo->program->mutex);
	return (arg);
}

void	create_threads(t_program *program)
{
	int	i;
	t_philo	*philos;
	pthread_mutex_t mutex;

	i = 1;
	philos = malloc(sizeof(t_philo) * (program->total_philo + 1));
	philos[program->total_philo].num = 0;
	philos[0].num = 0;
	program->mutex = &mutex;
	
	// I first create each philo, to make sure I have all the data once I run the threads
	while (i <= program->total_philo)
	{
		philos[i].num = i;
		philos[i].status = 1;
		philos[i].left_fork = 1;
		philos[i].total_meals = 0;
		philos[i].last_meal = program->timestamp_start; // Change timestamp to more recent
		philos[i].program = program;
		philos[i].philos = philos;
		i++;
	}
	i = 1;
	pthread_mutex_init(&mutex, NULL);
	while (i <= program->total_philo)
	{
		pthread_create(&philos[i].td, NULL, &routine, &philos[i]);
		i++;
	}
	i = 1;
	while (i <= program->total_philo)
	{
		pthread_join(philos[i].td, NULL);
		i++;
	}
	pthread_mutex_destroy(&mutex);
}
