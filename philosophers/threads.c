/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:23:19 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 16:29:19 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_error(char *message, t_program *program, t_philo *philos)
{
	printf("%s\n", message);
	destroy_program(program, philos);
}

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

int	end_simulation(t_program *program)
{
	int	ret;

	pthread_mutex_lock(program->sim_mutex);
	ret = program->end_simulation;
	pthread_mutex_unlock(program->sim_mutex);
	return (ret);
}

int	is_full(t_philo *philo)
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
	if ((philo->index + 1) % 2 == 0)
		ft_usleep(50);
	while (!end_simulation(philo->program))
	{
		if (!is_full(philo))
		{
			pthread_mutex_lock(philo->fork_mutex);
			if (philo->left_fork && right_fork(philo) && philo->status == 1)
			{
				take_two_forks(philo, philo->program);
				start_eating(philo, philo->program);
				start_sleeping(philo, philo->program);
				start_thinking(philo, philo->program);
			}
			else
				pthread_mutex_unlock(philo->fork_mutex);
		}
	}
	return (arg);
}
