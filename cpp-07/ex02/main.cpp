/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:00:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/05 19:36:12 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

void	test_int(void)
{
	std::cout << BBLUE << "--- Test with array of integers ---" << WHITE << std::endl;

	Array<int> nums(4);

	std::cout << "Size of new array: " << nums.size() << std::endl;

	std::cout << BLUE << "Printing array..." << WHITE << std::endl;
	nums.print_array();

	std::cout << BLUE << "Changing each number with its index..." << WHITE << std::endl;
	unsigned int	i = 0;
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
	std::cout << BLUE << "Default constructor then assignment operator, changed first element" << WHITE << std::endl;
	Array <int> unknown;
	unknown = nums;
	unknown[0] = 999;
	std::cout << BLUE << "Printing unknown array after assignment operator..." << WHITE << std::endl;
	unknown.print_array();
	std::cout << BLUE << "Nums array should not have changed..." << WHITE << std::endl;
	nums.print_array();

	// Copy constructor
	std::cout << BLUE << "Copy constructor" << WHITE << std::endl;
	Array <int>copy(nums);
	std::cout << BLUE << "Printing copy..." << WHITE << std::endl;
	nums.print_array();
}

void	test_char(void)
{
	std::cout << BBLUE << "\n--- Test with array of characters ---" << WHITE << std::endl;

	Array<char> word(8);
	unsigned int	i = 0;

	std::cout << "Size of new array: " << word.size() << std::endl;

	std::cout << BLUE << "Changing each number with letter..." << WHITE << std::endl;
	while (i < word.size())
	{
		try
		{
			word[i] = i + 97;
			i++;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
		}
	}
	std::cout << BLUE << "Printing array..." << WHITE << std::endl;
	word.print_array();
}

void	test_double()
{
	std::cout << BBLUE << "\n--- Test with array of doubles ---" << WHITE << std::endl;

	Array<float> dub(6);
	unsigned int	i = 0;

	std::cout << "Size of new array: " << dub.size() << std::endl;

	std::cout << BLUE << "Changing each number with double..." << WHITE << std::endl;
	while (i < dub.size())
	{
		try
		{
			dub[i] = i + 0.2;
			i++;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
		}
	}
	std::cout << BLUE << "Printing array..." << WHITE << std::endl;
	dub.print_array();
}

int main(void)
{
	test_int();
	test_char();
	test_double();
	return 0;
}


// #define MAX_VAL 750
// #include <cstdlib>
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }
