/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 17:18:06 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Constructor called\n";
}
ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
	std::cout << "Constructor called\n";
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called\n";
}
ScalarConverter&	ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	std::cout << "Assignment operator called\n";
	return (*this);
}

void	ScalarConverter::convert(std::string lit)
{
	int	len = lit.length();
	std::stringstream	stream;
	int		precision;

	if (lit == "+inf" || lit == "-inf" || lit == "nan" || lit == "-inff" || lit == "+inff" )
		special_values(lit);

	else if (len > 1 && lit[len - 1] == 'f')
	{
		float	f;
		stream << lit;
		stream >> f;
		precision = get_precision_float(lit);
		handle_float(f, precision);
	}
	else if (is_int(lit))
	{
		int	i;
		stream << lit;
		stream >> i;
		handle_int(i);
	}
	else if (is_double(lit))
	{
		double	d;
		stream << lit;
		stream >> d;
		precision = get_precision_double(lit);
		handle_double(d, precision);
	}
	else if (len == 1 && (lit[0] < 48 || lit[0] > 57) )
	{
		char	c;
		stream << lit;
		stream >> c;
		handle_char(lit[0]);
	}
	else
		std::cout << "The argument to convert must be one of those types: char, int, float, double\n";
};