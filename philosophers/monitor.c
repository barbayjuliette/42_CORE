/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:49:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 16:31:35 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Checks both 
//  - Meal condition
//  - time_to_die
// If one of the conditions is met, end_simulation = 1
// Routine stopped
// Actions stopped

void	set_end_simulation(t_program *program)
{
	pthread_mutex_lock(program->sim_mutex);
	program->end_simulation = 1;
	pthread_mutex_unlock(program->sim_mutex);
}

int	philo_dies(t_program *p, t_philo *philos)
{
	int	i;
	int	time;

	i = 0;
	while (i < p->total_philo)
	{
		time = get_timestamp() - p->timestamp_start;
		if (!is_full(&philos[i]) && time - philos[i].last_meal > p->time_to_die)
		{
			print_message(p->print_mutex, time, philos[i].index, "died");
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_enough_meals(t_philo *philos, t_program *program)
{
	int	i;

	i = 0;
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

void	*monitor(void *arg)
{
	t_philo		*philos;
	t_program	*program;

	philos = ((t_philo *)arg)->philos;
	program = ((t_philo *)arg)->program;
	while (!end_simulation(program))
	{
		if (all_enough_meals(philos, program) || philo_dies(program, philos))
		{
			set_end_simulation(program);
			return (arg);
		}
	}
	return (arg);
}
