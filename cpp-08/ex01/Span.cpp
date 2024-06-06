/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:43:31 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/06 19:00:45 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
}

Span::Span(unsigned int N)
{
	nums.reserve(N);
}


Span::Span( const Span & src )
{
	this->nums = src.nums;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->nums = rhs.nums;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int num)
{

	// std::cout << "Capacity: " << nums.capacity() << std::endl;
	// std::cout << "Size: " << nums.size() << std::endl;
	if (nums.size() >= nums.capacity())
		throw (std::runtime_error("Not enough space in this Span to add a new element."));
	nums.push_back(num);
}

int		Span::shortestSpan(void)
{
	if (nums.size() < 2)
		throw (std::runtime_error("Not enough elements to find shortest span"));
	std::vector<int> sorted = nums;

	std::sort(sorted.begin(), sorted.end());
	int		span = INT_MAX;
	unsigned int		i = 0;
	int		diff;

	while (i < sorted.size() - 1)
	{
		diff = sorted[i + 1] - sorted[i];
		if (diff < span)
			span = diff;
		i++;
	}
	return (span);
}

int		Span::longestSpan(void)
{
	if (nums.size() < 2)
		throw (std::runtime_error("Not enough elements to find longest span"));

	return (*max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end()));
}

void	display_int(int n)
{
	std::cout << n << std::endl;
}

void	Span::print(void) const
{
	for_each(nums.begin(), nums.end(), display_int);
	std::cout << std::endl;
}

void	addManyNumbers(std::vector<int> toAddNum)
{
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */