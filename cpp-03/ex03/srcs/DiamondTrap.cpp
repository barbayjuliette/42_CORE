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

#include "../includes/ClapTrap.hpp"
#include "../includes/DiamondTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/ScavTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("default_crap_trap"), ScavTrap("default", 100, 50, 20), FragTrap("default", 100, 100, 30)
{
	this->_name = "default";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << get_name() << " DiamondTrap created with default constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):  ClapTrap(name + "_clap_name"), ScavTrap(name, 100, 50, 20), FragTrap(name, 100, 100, 30)
{
	this->_name = "name";
	this->_hit_points = FragTrap::_hit_points;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << get_name() << " DiamondTrap created here!" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << get_name() << " DiamondTrap destroyed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	std::cout << "Copy constructor Scav called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& clap)
{
	ClapTrap::operator=(clap);
	std::cout << "Assignment operator Scav called" << std::endl;
	return (*this);
}


