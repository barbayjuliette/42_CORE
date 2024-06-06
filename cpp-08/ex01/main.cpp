/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:13:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/06 18:55:41 by jbarbay          ###   ########.fr       */
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
		std::cerr << e.what() << '\n';
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

int main(void)
{
	test_subject();
	test_copy();
	test_100();
	return 0;
}
