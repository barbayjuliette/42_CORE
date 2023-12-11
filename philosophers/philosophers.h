/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:45:21 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/11 21:51:20 by jbarbay          ###   ########.fr       */
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
} t_program;

typedef	struct s_philo
{
	pthread_t	td;
	int	num;
	int	status;
	int	fork;
	int	total_meals;
	unsigned long	last_meal;
} t_philo;

// Statuses:
//  1: Think
//  2: Take a fork
//  4: Eat
//  4: Sleep

// Helpers
int	ft_atoi(char *str);

#endif
