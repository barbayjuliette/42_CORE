/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:05:18 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 19:44:59 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
#define __WHATEVER_H__

#include <iostream>

template <typename T> 
void swap(T& x, T& y)
{
	T temp = x;
	
	x = y;
	y = temp;
}

template <typename T> 
T const & max(T const & x, T const & y)
{
	return ((x > y) ? x : y);
}

template <typename T> 
T const & min(T const & x, T const & y)
{
	return ((x < y) ? x : y);
}

#endif