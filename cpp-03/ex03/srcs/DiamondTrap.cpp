/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:24:48 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 23:54:36 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_crap_trap"), ScavTrap(), FragTrap()
{
	this->_name = "default";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << get_name() << " DiamondTrap created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ScavTrap(name), FragTrap(name), ClapTrap(name + "_clap_name")
{
	this->_name = "name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << get_name() << " DiamondTrap created!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << get_name() << " DiamondTrap destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy):  ScavTrap(copy), FragTrap(copy), ClapTrap(copy)
{
	std::cout << "Copy constructor Scav called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& clap)
{
	ClapTrap::operator=(clap);
	std::cout << "Assignment operator Scav called" << std::endl;
	return (*this);
}
