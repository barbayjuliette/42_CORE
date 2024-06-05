/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:26:47 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/05 19:55:44 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
#define __ITER_H__

#include <iostream>
#define WHITE "\e[97m"
#define BLUE "\e[0;36m"

template <typename T>
void	print_whatever(T& t)
{
	std::cout << t << " ";
}

template <typename T>
void iter(T *array, size_t len, void(*f)(T&))
{
	size_t	i = 0;

	while (i < len)
	{
		f(array[i]);
		i++;
	}
}

#endif
