/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:42:25 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/09 15:25:47 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <exception>
#include <algorithm>
#define WHITE "\e[0;97m"
#define RED "\e[31m"
#define BBLUE "\e[1;36m"
#define BLUE "\e[0;36m"

template <typename T>
typename T::const_iterator	easyfind(T &array, int num)
{
	typename T::const_iterator found = find(array.begin(), array.end(), num);
	if (found == array.end())
		throw std::runtime_error("Number not found");
	return (found);
}