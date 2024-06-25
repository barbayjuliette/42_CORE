/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:05:55 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 13:23:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

// Construction
ATarget::ATarget()
{
	std::cout << "Default constructor called\n";
}

ATarget::ATarget(const ATarget& obj) : _type(obj.getType())
{
	std::cout << "Copy constructor called\n";
}


ATarget::ATarget(std::string type) : _type(type)
{
	std::cout << _type << ": This looks like another boring day" << std::endl;
}

ATarget& ATarget::operator=(ATarget const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs.getType();
	}
	return (*this);
}

ATarget::~ATarget()
{
	std::cout << _type << ": My job here is done!" << std::endl;
}

// GETTERS
const std::string &	ATarget::getType() const
{
	return (_type);
}

// Member functions
void	ATarget::getHitBySpell(const ASpell & spell)
{
	std::cout << getType() << " has been " << spell.getEffects() << std::endl;
}