/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:41:37 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/03 16:13:10 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base::~Base()
{
	std::cout << "Base destructor called" << std::endl;
}

Base * Base::generate(void)
{
	std::srand(std::time(0));
	int random_num = rand();
	Base *instance;
	
	if (random_num % 3 == 0)
		instance = new A();
	if (random_num % 3 == 1)
		instance = new B();
	if (random_num % 3 == 2)
		instance = new C();
	return (instance);
}

void Base::identify(Base* p)
{
	// std::cout << "function called with pointer: ";
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unknown type\n";
}

void Base::identify(Base& p)
{
	// std::cout << "function called with reference: ";
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "C" << std::endl;
		}
	}
}