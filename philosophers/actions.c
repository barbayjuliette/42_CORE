/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 16:46:45 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_two_forks(t_philo *philo, t_program *prog)
{
	int		i;
	int		timestamp;
	char	*msg;

	msg = "has taken a fork";
	if (end_simulation(prog))
	{
		pthread_mutex_unlock(philo->fork_mutex);
		return ;
	}
	i = (philo->index) - 1;
	if (i < 0)
		i = prog->total_philo - 1;
	(philo->philos)[i].left_fork = 0;
	pthread_mutex_unlock(philo->fork_mutex);
	timestamp = get_timestamp() - prog->timestamp_start;
	print_message(prog->print_mutex, timestamp, philo->index, msg);
	pthread_mutex_lock(philo->fork_mutex);
	philo->left_fork = 0;
	pthread_mutex_unlock(philo->fork_mutex);
	timestamp = get_timestamp() - prog->timestamp_start;
	print_message(prog->print_mutex, timestamp, philo->index, msg);
}

void	start_eating(t_philo *philo, t_program *prog)
{
	int	timestamp;

	if (end_simulation(prog))
		return ;
	timestamp = get_timestamp() - prog->timestamp_start;
	print_message(prog->print_mutex, timestamp, philo->index, "is eating");
	philo->last_meal = timestamp;
	philo->total_meals++;
	if (philo->total_meals == prog->max_meals)
	{
		pthread_mutex_lock(prog->meals_mutex);
		philo->is_full = 1;
		pthread_mutex_unlock(prog->meals_mutex);
	}
	ft_usleep(prog->time_to_eat);
}

void	start_sleeping(t_philo *philo, t_program *prog)
{
	int	timestamp;
	int	i;

	if (end_simulation(prog))
		return ;
	timestamp = get_timestamp() - prog->timestamp_start;
	i = (philo->index) - 1;
	if (i < 0)
		i = prog->total_philo - 1;
	pthread_mutex_lock(philo->fork_mutex);
	(philo->philos)[i].left_fork = 1;
	philo->left_fork = 1;
	pthread_mutex_unlock(philo->fork_mutex);
	print_message(prog->print_mutex, timestamp, philo->index, "is sleeping");
	ft_usleep(prog->time_to_sleep);
}

void	start_thinking(t_philo *philo, t_program *prog)
{
	int	timestamp;

	if (end_simulation(prog))
		return ;
	timestamp = get_timestamp() - prog->timestamp_start;
	print_message(prog->print_mutex, timestamp, philo->index, "is thinking");
	if (prog->total_philo % 2 == 1)
		ft_usleep(1);
}
