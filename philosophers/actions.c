/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/02 13:34:13 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_two_forks(t_philo *philo)
{
	int	i;
	int	timestamp;

	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;

	pthread_mutex_lock(philo->fork_mutex);
	(philo->philos)[i].left_fork = 0;
	pthread_mutex_unlock(philo->fork_mutex);
	timestamp = get_timestamp() - philo->program->timestamp_start;
	pthread_mutex_lock(philo->program->print_mutex);
	printf("%d %d has taken a fork\n", timestamp, philo->index + 1);
	pthread_mutex_unlock(philo->program->print_mutex);

	pthread_mutex_lock(philo->fork_mutex);
	philo->left_fork = 0;
	pthread_mutex_unlock(philo->fork_mutex);

	timestamp = get_timestamp() - philo->program->timestamp_start;
	pthread_mutex_lock(philo->program->print_mutex);
	printf("%d %d has taken a fork\n", timestamp, philo->index + 1);
	pthread_mutex_unlock(philo->program->print_mutex);
	philo->status = 2;
}

void	start_eating(t_philo *philo)
{
	int	timestamp;

	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 3;

	pthread_mutex_lock(philo->program->print_mutex);
	printf("%d %d is eating\n", timestamp, philo->index + 1);
	pthread_mutex_unlock(philo->program->print_mutex);

	philo->last_meal = timestamp;
	ft_usleep(philo->program->time_to_eat);
	philo->total_meals++;
	if (philo->total_meals == philo->program->max_meals)
	{
		pthread_mutex_lock(philo->program->meals_mutex);
		philo->is_full = 1;
		pthread_mutex_unlock(philo->program->meals_mutex);
	}
}

void	start_sleeping(t_philo *philo)
{
	int	timestamp;
	int	i;

	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 4;
	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;
	pthread_mutex_lock(philo->fork_mutex);
	(philo->philos)[i].left_fork = 1;
	philo->left_fork = 1;
	pthread_mutex_unlock(philo->fork_mutex);
	pthread_mutex_lock(philo->program->print_mutex);
	printf("%d %d is sleeping\n", timestamp, philo->index + 1);
	pthread_mutex_unlock(philo->program->print_mutex);
	ft_usleep(philo->program->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	int	timestamp;

	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 1;
	pthread_mutex_lock(philo->program->print_mutex);
	printf("%d %d is thinking\n", timestamp, philo->index + 1);
	pthread_mutex_unlock(philo->program->print_mutex);
}
