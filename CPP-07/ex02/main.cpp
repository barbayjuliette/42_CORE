/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/04 21:31:58 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	test_int(void)
{
	std::cout << BBLUE << "--- Test with array of integers ---" << WHITE << std::endl;
	
	Array<int> nums(4);
	unsigned int	i = 0;
	
	std::cout << "Size of new array: " << nums.size() << std::endl;
	
	std::cout << BLUE << "Printing array..." << WHITE << std::endl;
	nums.print_array();
	
	std::cout << BLUE << "Changing each number with its index..." << WHITE << std::endl;
	while (i < nums.size())
	{
		try
		{
			nums[i] = i;
			i++;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
		}
	}
	std::cout << BLUE << "Printing array..." << WHITE << std::endl;
	nums.print_array();

	std::cout << BLUE << "Trying to access index out of bound: " << WHITE << std::endl;
	try
	{
		nums[nums.size()] = i;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
	}

	// Default constructor
	Array <int> unknown;
	// Assignment operator
	// Copy constructor
	
}

int main(void)
{
	test_int();
	return 0;
}
