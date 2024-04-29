/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:23:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 17:11:41 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

const std::string&	Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "Type changed to: " << this->_type << std::endl;
}

Weapon::Weapon(std::string type): _type(type)
{
	std::cout << "Weapon constructor called: " << this->_type << "\n";
}

Weapon::Weapon(void)
{
	std::cout << "Weapon constructor" << "\n";
}

Weapon::~Weapon(void)
{
	std::cout << "Weapon deconstructor called: " << this->_type << "\n";
}
