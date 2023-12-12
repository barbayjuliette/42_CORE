/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:30:04 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/12 14:31:54 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_two_forks(t_philo *philo)
{
	int	i;
	
	i = (philo->num) - 1;
	if (i == 0)
		i = philo->program->total_philo;
	(philo->philos)[i].left_fork = 0;
	printf("%ld %d has taken a fork\n", get_timestamp(), philo->num);
	philo->left_fork = 0;
	printf("%ld %d has taken a fork\n", get_timestamp(), philo->num);
	philo->status = 2;
}

void	start_eating(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_timestamp();
	philo->status = 3;
	printf("%ld %d is eating\n", timestamp, philo->num);
	philo->last_meal = timestamp;
	usleep(philo->program->time_to_eat * 1000);
	philo->total_meals++;

}

void	start_sleeping(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_timestamp();
	philo->status = 4;
	printf("%ld %d is sleeping\n", timestamp, philo->num);
	usleep(philo->program->time_to_sleep * 1000);
}

void	start_thinking(t_philo *philo)
{
	unsigned long	timestamp;

	timestamp = get_timestamp();
	philo->status = 1;
	printf("%ld %d is thinking\n", timestamp, philo->num);
}