/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:05:18 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 19:21:47 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
#define __WHATEVER_H__

#include <iostream>

template <typename T> void swap(T& x, T& y)
{
	T temp = x;
	
	x = y;
	y = temp;
}

template <typename T> T max(T x, T y)
{
	return ((x > y) ? x : y);
}

template <typename T> T min(T x, T y)
{
	return ((x < y) ? x : y);
}

#endif