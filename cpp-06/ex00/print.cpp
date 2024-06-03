/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:04:11 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 17:27:27 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "ScalarConverter.hpp"

void	special_values(std::string	lit)
{
	float	float_value;
	double	double_value;

	if (lit == "+inf" || lit == "+inff")
	{
		float_value = std::numeric_limits<float>::infinity();
		double_value = std::numeric_limits<double>::infinity();
	}
	else if (lit == "-inf" || lit == "-inff")
	{
		float_value = -std::numeric_limits<float>::infinity();
		double_value = -std::numeric_limits<double>::infinity();
	}
	else
	{
		float_value = std::numeric_limits<float>::quiet_NaN();
		double_value = std::numeric_limits<double>::quiet_NaN();
	}
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << float_value << 'f' << std::endl;
	std::cout << "double: " << double_value << std::endl;
}

void	handle_float(float num, int precision)
{
	if (is_displayable(static_cast<int>(num)))
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: " << num << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

int 	is_displayable(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	handle_int(int num)
{
	if (is_displayable(static_cast<int>(num)))
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(num) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(num) << std::endl;
}

void	handle_double(double num, int precision)
{
	if (is_displayable(static_cast<int>(num)))
		std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(num) << std::endl;
	std::cout << std::fixed << std::setprecision(precision);
	std::cout << "float: " << static_cast<float>(num) << 'f' << std::endl;
	std::cout << "double: " << num << std::endl;
}

void	handle_char(char c)
{	
	if (is_displayable(static_cast<int>(c)))
		std::cout << "char: " << "'" << static_cast<char>(c) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}
