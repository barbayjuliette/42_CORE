/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:50 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/16 19:02:49 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RNP::RNP(void)
{

}

RNP::RNP(std::string exp) : exp(exp)
{

}


// Copy constructor
RNP::RNP(const RNP& copy) : exp(copy.exp)
{

}

// Assignment operator
RNP&	RNP::operator=(RNP const& rhs)
{
	if (this != &rhs)
	{
		this->exp = rhs.exp;
	}
	return (*this);
}

// Destructor
RNP::~RNP(void)
{

}

void	RNP::calculate(char operation, std::stack<std::string> & stack)
{
	float	result;
	std::stringstream	stream;

	if (stack.empty())
		throw (std::runtime_error("syntax"));
	std::string	num1 = stack.top();
	stack.pop();
	if (stack.empty())
		throw (std::runtime_error("syntax"));
	std::string	num2 = stack.top();
	stack.pop();

	if (operation == '-')
		result = std::atof(num2.c_str()) - std::atof(num1.c_str());
	else if (operation == '+')
		result = std::atof(num2.c_str()) + std::atof(num1.c_str());
	else if (operation == '/')
	{
		if (num1[0] == '0')
			throw (std::runtime_error("division by zero not allowed"));
		result = std::atof(num2.c_str()) / std::atof(num1.c_str());
	}
	else
		result = std::atof(num2.c_str()) * std::atof(num1.c_str());
	stream << result;
	stack.push(stream.str());
}

// Member functions
void	RNP::process_stack()
{
	std::stack<std::string> stack;

	std::stringstream 	stream(exp);
	std::string			num;
	while (stream >> num)
	{
		if (isdigit(num[0]))
			stack.push(num);
		else
			calculate(num[0], stack);
	}
	if (stack.size() != 1)
		throw (std::runtime_error("syntax"));
	std::cout << std::fixed << std::setprecision(2) << stack.top() << std::endl;
}

bool	RNP::isoperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return (true);
	return (false);
}

void	RNP::check_errors()
{
	std::stringstream 	stream(exp);
	std::string			num;

	if (exp == "")
		throw (std::runtime_error("argument cannot be empty"));
	while (stream >> num)
	{
		if (!isdigit(num[0]) && !isoperator(num[0]))
			throw (std::runtime_error("Only accepts numbers < 10 and operators +-?* "));
		if (num.length() != 1)
			throw (std::runtime_error("Only accepts numbers < 10 and operators +-?* "));
	}
}
