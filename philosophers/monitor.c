/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 15:49:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 15:49:43 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Checks both 
//  - Meal condition
//  - time_to_die
// If one of the conditions is met, end_simulation = 1
// Routine stopped
// Actions stopped

void	*monitor(void *arg)
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
		if (all_enough_meals(philos, program))
		{
			pthread_mutex_lock(philos[i].program->sim_mutex);
			philos[i].program->end_simulation = 1;
			pthread_mutex_unlock(philos[i].program->sim_mutex);
			return (arg);
		}
		while (i < program->total_philo)
		{
			if (!philo_is_full(&philos[i]))
			{
				timestamp = get_timestamp() - philos[i].program->timestamp_start;
				if (timestamp - philos[i].last_meal > program->time_to_die)
				{
					print_message(program->print_mutex, timestamp, philos[i].index + 1, "died");
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