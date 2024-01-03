/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 14:40:49 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_two_forks(t_philo *philo)
{
	int	i;
	int	timestamp;

	if (end_simulation(philo->program))
	{
		pthread_mutex_unlock(philo->fork_mutex);
		return ;
	}
	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;
	// pthread_mutex_lock(philo->fork_mutex);
	(philo->philos)[i].left_fork = 0;
	pthread_mutex_unlock(philo->fork_mutex);
	
	timestamp = get_timestamp() - philo->program->timestamp_start;
	print_message(philo->program->print_mutex, timestamp, philo->index + 1, "has taken a fork");

	pthread_mutex_lock(philo->fork_mutex);
	philo->left_fork = 0;
	pthread_mutex_unlock(philo->fork_mutex);
	
	timestamp = get_timestamp() - philo->program->timestamp_start;
	print_message(philo->program->print_mutex, timestamp, philo->index + 1, "has taken a fork");
	
	philo->status = 2;
}

void	start_eating(t_philo *philo)
{
	int	timestamp;

	if (end_simulation(philo->program))
		return ;
	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 3;

	print_message(philo->program->print_mutex, timestamp, philo->index + 1, "is eating");

	philo->last_meal = timestamp;
	philo->total_meals++;
	if (philo->total_meals == philo->program->max_meals)
	{
		pthread_mutex_lock(philo->program->meals_mutex);
		philo->is_full = 1;
		pthread_mutex_unlock(philo->program->meals_mutex);
	}
	ft_usleep(philo->program->time_to_eat);
}

void	start_sleeping(t_philo *philo)
{
	int	timestamp;
	int	i;

	if (end_simulation(philo->program))
		return ;
	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 4;
	i = (philo->index) - 1;
	if (i < 0)
		i = philo->program->total_philo - 1;
	pthread_mutex_lock(philo->fork_mutex);
	(philo->philos)[i].left_fork = 1;
	philo->left_fork = 1;
	pthread_mutex_unlock(philo->fork_mutex);
	print_message(philo->program->print_mutex, timestamp, philo->index + 1, "is sleeping");
	ft_usleep(philo->program->time_to_sleep);
}

void	start_thinking(t_philo *philo)
{
	int	timestamp;

	if (end_simulation(philo->program))
		return ;
	timestamp = get_timestamp() - philo->program->timestamp_start;
	philo->status = 1;
	print_message(philo->program->print_mutex, timestamp, philo->index + 1, "is thinking");
	if (philo->program->total_philo % 2 == 1)
		ft_usleep(1);
}
