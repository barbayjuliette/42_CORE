/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:05:28 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/05 20:04:33 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print_int(int & num)
{
	std::cout << num * 100 << std::endl;
}

void print_char(char & c)
{
	std::cout << c << std::endl;
}

void print_double(double & dub)
{
	std::cout << dub << std::endl;
}

void to_lower_case(char & c)
{
	if (c >= 65 && c <= 90)
		c += 32;
}


int main(void)
{
	int nums[] = {5, 9, 8, 3, 6};
	double doubles[] = {5.56, 98.32, 87.321, 8.2};
	char str[] = {'H', 'E', 'L', 'L', 'O'};

	std::cout << BLUE << "With array of integers" << WHITE << std::endl;
	iter(nums, 5, &print_int);

	std::cout << std::endl << BLUE << "With array of characters" << WHITE << std::endl;
	iter(str, 5, &to_lower_case);
	iter(str, 5, &print_char);

	std::cout << std::endl << BLUE << "With array of doubles" << WHITE << std::endl;
	iter(doubles, 4, &print_double);

	std::cout << std::endl << BLUE << "With template function" << WHITE << std::endl;
	iter(nums, 5, &print_whatever);
	std::cout << std::endl;
	iter(str, 5, &print_whatever);
	std::cout << std::endl;
	iter(doubles, 4, &print_whatever);
	std::cout << std::endl;
	return (0);
}
