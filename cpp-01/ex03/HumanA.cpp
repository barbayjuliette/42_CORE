/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:51:36 by jbarbay           #+#    #+#             */
/*   Updated: 2024/04/25 17:42:57 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " <<  this->_weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) :  _weapon(weapon), _name(name)
{
	std::cout << "Created Human A " << this->_name << " with weapon " << this->_weapon.getType() << std::endl;
}

HumanA::~HumanA(void)
{
	std::cout << "Deconstructed A: " << this->_name << " with weapon " << this->_weapon.getType() << std::endl;
}
