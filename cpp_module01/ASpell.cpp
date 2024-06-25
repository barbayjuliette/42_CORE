/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:05 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 13:17:05 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

// Construction
ASpell::ASpell()
{
	std::cout << "Default constructor called\n";
}

ASpell::ASpell(const ASpell& obj) : _name(obj.getName()), _effects(obj.getEffects())
{
	std::cout << "Copy constructor called\n";
}


ASpell::ASpell(std::string name, std::string title) : _name(name), _effects(title)
{
	std::cout << _name << ": This looks like another boring day" << std::endl;
}

ASpell& ASpell::operator=(ASpell const & rhs)
{
	if (this != &rhs)
	{
		this->_effects = rhs.getEffects();
		this->_name = rhs.getName();
	}
	return (*this);
}

ASpell::~ASpell()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

// GETTERS
const std::string	ASpell::getName() const
{
	return (_name);
}

const std::string	ASpell::getEffects() const
{
	return (_effects);
}
