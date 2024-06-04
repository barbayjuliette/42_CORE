/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:26:47 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/04 16:45:34 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
#define __ITER_H__

#include <iostream>
#define WHITE "\e[97m"
#define BLUE "\e[0;36m"

template <typename T> 
void	print_whatever(const T& t)
{
	std::cout << t << " ";
}

template <typename T> 
void iter(const T *array, size_t len, void(*f)(const T&))
{
	size_t	i = 0;

	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

#endif