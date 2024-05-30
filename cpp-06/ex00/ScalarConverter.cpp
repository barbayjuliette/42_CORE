/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:13:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/30 18:51:33 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
// #include "check_type.cpp"
// #include "print.cpp"

// CANONICAL CLASS

ScalarConverter::ScalarConverter()
{
	std::cout <<"Constructor called\n";
}
ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void)src;
	std::cout <<"Constructor called\n";
}
ScalarConverter::~ScalarConverter()
{
	std::cout <<"Destructor called\n";
}
ScalarConverter&	ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	std::cout <<"Assignment operator called\n";
	return (*this);
}

// Check Type

int	get_precision_float(std::string lit)
{
	int	i = 0;
	int	count = 0;
	while (lit[i] != 46)
		i++;
	i++;
	while (lit[i] != 'f' && lit[i])
	{
		i++;
		count++;
	}
	count = ( count == 0 ? 1 : count);
	return (count);
}

int	get_precision_double(std::string lit)
{
	int	i = 0;
	int	count = 0;
	while (lit[i] != 46)
		i++;
	i++;
	while (lit[i])
	{
		i++;
		count++;
	}
	count = ( count == 0 ? 1 : count);
	return (count);
}

int	is_int(std::string lit)
{
	int	i = 0;

	while (lit[i])
	{
		if (!isdigit(lit[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_double(std::string lit)
{
	int	i = 0;

	while (lit[i])
	{	
		if (lit[i] == 46 && i++)
			continue ;
		if (lit[0] < 48 || lit[0] > 57 )
			return (0);
		i++;
	}
	return (1);
}

// PRINT

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
	std::cout << lit << std::endl;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << float_value << 'f' << std::endl;
	std::cout << "double: " << double_value << std::endl;
}

void	handle_float(float num, int precision)
{
	std::cout << "char: " << "'" << static_cast<char>(num) << "'" << std::endl;
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
		std::cout << "char: " << static_cast<char>(num) << std::endl;
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
		std::cout << "char: " << static_cast<char>(num) << std::endl;
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
		std::cout << "char: " << static_cast<char>(c) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << 'f' << std::endl;
	std::cout << "double: " << static_cast<int>(c) << std::endl;
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
		// std::cout << "FLOAT\n";
		float	f;
		stream << lit;
		stream >> f;
		precision = get_precision_float(lit);
		handle_float(f, precision);
	}
	else if (is_int(lit))
	{
		int	i;
		// std::cout << "INT\n";
		stream << lit;
		stream >> i;
		handle_int(i);
	}
	else if (is_double(lit))
	{
		double	d;
		// std::cout << "DOUBLE\n";
		stream << lit;
		stream >> d;
		precision = get_precision_double(lit);
		handle_double(d, precision);
	}
	else if (len == 1 && (lit[0] < 48 || lit[0] > 57) )
	{
		char	c;
		// std::cout << "CHAR\n";
		stream << lit;
		stream >> c;
		handle_char(lit[0]);
	}
}