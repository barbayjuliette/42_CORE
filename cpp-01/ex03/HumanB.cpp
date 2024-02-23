/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:11:14 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/22 23:08:23 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name)
{
	std::cout << "Created Human B " << this->_name << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "Decreated Human B " << this->_name << std::endl;
}

void HumanB::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}
