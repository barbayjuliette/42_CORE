/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 15:50:27 by jbarbay          ###   ########.fr       */
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

# define ENOUGH_MEALS 2

typedef struct s_program
{
	int				total_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				end_simulation;
	unsigned long	timestamp_start;
	pthread_mutex_t	*meals_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*sim_mutex;
} t_program;

typedef	struct s_philo
{
	pthread_t		td;
	int				index;
	int				status;
	int				left_fork;
	int				total_meals;
	int				is_full;
	int				dead;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*status_mutex;
	int				last_meal;
	struct s_philo	*philos;
	t_program		*program;
} t_philo;

// Statuses:
//  1: Think
//  2: Take a fork
//  3: Eat
//  4: Sleep
//  5: Dying

// Helpers
int		ft_atoi(char *str);
int		ft_usleep(size_t milliseconds);
size_t	get_timestamp();
void	ft_error(char *message, t_program *program, t_philo *philos);

// Input validation
int		valid_input(char *argv[], int argc);

// Threads

void	*routine(void *arg);
void	*monitor(void *arg);
int		all_enough_meals(t_philo *philos, t_program *program);
void	*is_dying(void *arg);

// Init Threads
void	create_threads(t_program *program);
void	initialize_philos(t_program *program, t_philo *philos);
int		start_threads(t_program *program, t_philo *philos);
int		join_threads(t_program *program, t_philo *philos);
void	destroy_program(t_program *program, t_philo *philos);

// Thread helpers
int		right_fork(t_philo *philo);
int		philo_is_full(t_philo *philo);
void	print_message(pthread_mutex_t *mutex, int timestamp, int id, char *string);

// Actions
void	take_two_forks(t_philo *philo);
void	start_eating(t_philo *philo);
void	start_sleeping(t_philo *philo);
void	start_thinking(t_philo *philo);
int		end_simulation(t_program *program);

#endif
