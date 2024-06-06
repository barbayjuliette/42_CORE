/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:42:28 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/06 13:11:20 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void	test_vector(void)
{
	std::vector<int>	nums;

	for (int i = 1; i <= 5; i++)
	{
		nums.push_back(i * 100);
	}
	try
	{
		std::vector<int>::const_iterator it = easyfind(nums, 200);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(nums, 201);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
	}
}

void	test_list(void)
{
	std::list<int>	nums;

	for (int i = 1; i <= 5; i++)
	{
		nums.push_back(i * 100);
	}
	try
	{
		std::list<int>::const_iterator it = easyfind(nums, 400);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(nums, 201);
		std::cout << "Found: " << *it << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
	}
}

int main(void)
{
	std::cout << BLUE << "--- Test with vector ---" << WHITE << std::endl;
	test_vector();
	std::cout << std::endl << BLUE << "--- Test with list ---" << WHITE << std::endl;
	test_list();
	return (0);
}


