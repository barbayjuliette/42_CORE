/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:21 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/12 14:33:01 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSPHERS_H
# define PHILOSPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h> // For memset

typedef struct s_program
{
	int	total_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	min_nb_eats_each;
	unsigned long	timestamp_start;
	pthread_mutex_t	*mutex;
} t_program;

typedef	struct s_philo
{
	pthread_t	td;
	int	num;
	int	status;
	int	left_fork;
	int	total_meals;
	unsigned long	last_meal;
	struct s_philo		*philos;
	t_program	*program;
} t_philo;

// Statuses:
//  1: Think
//  2: Take a fork
//  3: Eat
//  4: Sleep

// Helpers
int	ft_atoi(char *str);

// Input validation
int		valid_input(char *argv[], int argc);

// Threads
void	*routine(void *arg);
void	create_threads(t_program *program);

// Thread helpers
int		right_fork(t_philo *philo);

// Actions
void	take_two_forks(t_philo *philo);
void	start_eating(t_philo *philo);
void	start_sleeping(t_philo *philo);
void	start_thinking(t_philo *philo);



unsigned long	get_timestamp();

#endif
