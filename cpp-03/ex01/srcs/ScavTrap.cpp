/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:49:41 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 20:49:19 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"
#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap("Default", 100, 50, 20)
{
	std::cout << get_name() << " ScavTrap created with default constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	std::cout << get_name() << " ScavTrap created!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << get_name() << " ScavTrap destroyed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& clap): ClapTrap(clap)
{
	std::cout << "Copy constructor Scav called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& clap)
{
	ClapTrap::operator=(clap);
	std::cout << "Assignment operator Scav called" << std::endl;
	return (*this);
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << get_name() << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if ( _energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
		_energy_points -= 1;
	}
	else if (_energy_points == 0)
		std::cout << "ScavTrap " << _name << " cannot attack, it has no energy points" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " cannot attack, it is dead" << std::endl;
}
