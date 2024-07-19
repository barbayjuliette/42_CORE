/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:13:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/09 15:24:57 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	test_subject()
{
	Span sp(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << '\n' << WHITE;
	}
	std::cout << "Capacity: " << sp.nums.capacity() << std::endl;
	std::cout << "Size: " << sp.nums.size() << std::endl;
}

void	test_exception()
{
	Span sp(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(12);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << '\n' << WHITE;
	}
}

void	test_copy()
{
	Span sp(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	Span copy(sp);
	copy.nums[0] = 999;

	std::cout << "Original" << std::endl;
	sp.print();
	std::cout << "Copy" << std::endl;
	copy.print();
}

void	test_100(void)
{
	Span sp(100000);
	srand(time(NULL));
	
	for (int i = 0; i < 100000; i++)
		sp.addNumber(rand());
	std::cout << "TEST 100 000 numbers" << std::endl;
	sp.print();
}

void	test_add_many_nums()
{
	Span sp(200);
	std::vector<int>	numsToAdd;
	// std::vector<int>	numsToAdd({1, 2, 3, 4, 5, 6, 7, 8, 9, 11});

	numsToAdd.reserve(201);
	srand(time(NULL));
	try
	{
		for (int i = 0; i < 200; i++)
			numsToAdd.push_back(rand());
		sp.addManyNumbers(numsToAdd.begin(), numsToAdd.end());
		sp.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << '\n' << WHITE;
	}
}

int main(void)
{
	std::cout << BLUE << "--- Test from subject ---" << WHITE << std::endl;
	test_subject();

	std::cout << std::endl << BLUE << "--- Test exception ---" << WHITE << std::endl;
	std::cout << "---> I try to add over the capacity" << std::endl;
	test_exception();

	std::cout << std::endl << BLUE << "--- Test copy ---" << WHITE << std::endl;
	std::cout << "---> Using copy constructor and make sure copy is deep" << std::endl;
	test_copy();

	// std::cout << std::endl << BLUE << "--- Test with 100 000 numbers ---" << WHITE << std::endl;
	// test_100();

	std::cout << std::endl << BLUE << "--- Test with addManyNumbers ---" << WHITE << std::endl;
	std::cout << "---> Add many numbers using a numbers vector" << std::endl;
	test_add_many_nums();

	return 0;
}
