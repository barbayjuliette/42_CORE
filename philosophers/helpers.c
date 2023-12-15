/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay < jbarbay@student.42singapore.s    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:08 by jbarbay           #+#    #+#             */
/*   Updated: 2023/12/15 19:15:29 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_atoi(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

unsigned long	get_timestamp()
{
	unsigned long	timestamp;
	struct	timeval time;

	gettimeofday(&time, NULL);
	timestamp = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (timestamp);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < milliseconds)
		usleep(500);
	return (0);
}