/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:04 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/15 17:26:26 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_two_forks(t_philo *philo)
{
	int	i;
	unsigned long	timestamp;
	
	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;

	
	(philo->philos)[i].left_fork = 0;
	timestamp = get_timestamp() - philo->program->timestamp_start;
	
	printf("%ld %d has taken a fork\n", timestamp, philo->index + 1);
	philo->left_fork = 0;

	timestamp = get_timestamp() - philo->program->timestamp_start;
	printf("%ld %d has taken a fork\n", timestamp, philo->index + 1);
	
	philo->status = 2;
}

void	start_eating(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 3;
	printf("%ld %d is eating\n", timestamp, philo->index + 1);
	philo->last_meal = timestamp;
	usleep(philo->program->time_to_eat * 1000);
	philo->total_meals++;
	if (philo->total_meals == philo->program->min_nb_eats_each)
	{
		pthread_mutex_lock(philo->program->meals_mutex);
		philo->is_full = 1;
		pthread_mutex_unlock(philo->program->meals_mutex);
	}
}

void	start_sleeping(t_philo *philo)
{
	unsigned long	timestamp;
	int	i;
	

	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 4;
	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;
	// pthread_mutex_lock(philo->program->fork_mutex);
	// pthread_mutex_lock(philo->program->meals_mutex);
	(philo->philos)[i].left_fork = 1;
	philo->left_fork = 1;
	// pthread_mutex_unlock(philo->program->fork_mutex);
	// pthread_mutex_unlock(philo->program->meals_mutex);
	printf("%ld %d is sleeping\n", timestamp, philo->index + 1);
	usleep(philo->program->time_to_sleep * 1000);
}

void	start_thinking(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 1;
	printf("%ld %d is thinking\n", timestamp, philo->index + 1);
}