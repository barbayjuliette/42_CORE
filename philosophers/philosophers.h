/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/01/03 17:30:56 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>

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
}	t_program;

typedef struct s_philo
{
	pthread_t		td;
	int				index;
	int				left_fork;
	int				total_meals;
	int				is_full;
	int				dead;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	*status_mutex;
	int				last_meal;
	struct s_philo	*philos;
	t_program		*program;
}	t_philo;

// Helpers
int		ft_atoi(char *str);
int		ft_usleep(size_t milliseconds);
size_t	get_timestamp(void);
void	ft_error(char *message, t_program *program, t_philo *philos);

// Input validation
int		valid_input(char *argv[], int argc);

// Threads
void	*routine(void *arg);
int		right_fork(t_philo *philo);
int		is_full(t_philo *philo);
void	print_message(pthread_mutex_t *mutex, int timestamp, int id, char *msg);

// Monitoring thread
void	*monitor(void *arg);
int		all_enough_meals(t_philo *philos, t_program *program);
int		philo_dies(t_program *p, t_philo *philos);
void	set_end_simulation(t_program *program);

// Init Threads
void	create_threads(t_program *program);
int		initialize_philos(t_program *program, t_philo *philos);
int		start_threads(t_program *program, t_philo *philos);
int		join_threads(t_program *program, t_philo *philos);
void	destroy_program(t_program *program, t_philo *philos);

// Actions
void	take_two_forks(t_philo *philo, t_program *prog);
void	start_eating(t_philo *philo, t_program *prog);
void	start_sleeping(t_philo *philo, t_program *prog);
void	start_thinking(t_philo *philo, t_program *prog);
int		end_simulation(t_program *program);

#endif
