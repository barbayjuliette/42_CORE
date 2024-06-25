/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:12 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 15:10:24 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dummy.hpp"

// Construction
Dummy::Dummy() : ATarget("Target Practice Dummy")
{
	std::cout << "Default constructor Dummy called\n";
}

Dummy::Dummy(const Dummy& obj) : ATarget(obj.getType())
{
	std::cout << "Copy constructor Dummy called\n";
}

Dummy& Dummy::operator=(Dummy const & rhs)
{
	if (this != &rhs)
		ATarget::operator=(rhs);
	return (*this);
}

Dummy::~Dummy()
{
	std::cout << _type << ": My job here is done!" << std::endl;
}


ATarget*	Dummy::clone() const
{
	Dummy*	copy = new Dummy();
	return (copy);
}

const std::string &	Dummy::getType() const
{
	return (this->_type);
}