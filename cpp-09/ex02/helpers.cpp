/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:44:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/14 21:22:01 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	is_sorted(std::vector<int> vector)
{
	size_t	i = 0;
	int	prev = INT_MIN;

	while ( i < vector.size())
	{
		if (vector[i] < prev)
			return (false);
		prev = vector[i];
		i++;
	}
	return (true);
}

bool	is_sorted(std::list<int> list)
{
	int							prev = INT_MIN;
	std::list<int>::iterator	it;
	for (it = list.begin(); it != list.end(); it++)
	{
		if (*it < prev)
			return (false);
		prev = *it;
	}
	return (true);
}

int	binary_search( std::vector<int> main, int x )
{
	int 	low = 0;
	int 	high = main.size();
	int		mid;

	while (low < high)
	{
		mid = ( low + high ) / 2;
		if ( x  < main[mid] )
			high = mid;
		else
			low = mid + 1;
	}
	return (low);
}

int	jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + jacobsthal(n - 2) * 2);
}

std::vector<int>	create_vector(char *argv[], int argc)
{
	std::vector<int>	unsorted_vector;
	int					i = 1;
	int					n;

	while (i < argc)
	{
		n = std::atoi(argv[i]);
		if (n <= 0)
			throw (std::runtime_error("Error: wrong input"));
		unsorted_vector.push_back(n);
		i++;
	}
	return (unsorted_vector);
}

void	print_vector(std::vector<int> vector)
{
	std::vector<int>::const_iterator	it;

	for (it = vector.begin(); it != vector.end(); it++)
	{
		std::cout << *it;
		std::cout << " ";
	}
}

void	print_list(std::list<int> list)
{
	std::list<int>::const_iterator	it;

	for (it = list.begin(); it != list.end(); it++)
	{
		std::cout << *it;
		std::cout << " ";
	}
}