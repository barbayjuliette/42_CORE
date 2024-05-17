/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 10:32:45 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 20:47:30 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("Default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << _name << " ClapTrap created with default constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << _name << " ClapTrap created!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << _name << " ClapTrap destroyed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clap)
{
	std::cout << "Copy constructor ClapTrap called" << std::endl;
	*this = clap;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& clap)
{
	std::cout << "Assignment operator called" << std::endl;
	this->_attack_damage = clap._attack_damage;
	this->_energy_points = clap._energy_points;
	this->_hit_points = clap._hit_points;
	this->_name = clap._name;
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if ( _energy_points > 0 && _hit_points > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
		_energy_points -= 1;
	}
	else if (_energy_points == 0)
		std::cout << "ClapTrap " << _name << " cannot attack, it has no energy points" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " cannot attack, it is dead" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points > 0)
	{
		_hit_points -= amount;
		if (_hit_points < 0)
			_hit_points = 0;
		std::cout << "ClapTrap " << _name << " was attacked and lost " << amount << " hit points. It has now " << _hit_points << " hit points" << std::endl;
	}
	else
		std::cout << _name << " cannot take damage anymore, it is dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points > 0 && _hit_points > 0)
	{
		_hit_points += amount;
		_energy_points -= 1;
		std::cout << "ClapTrap " << _name << " repaired itself and got " << amount << " points back" << std::endl;
	}
	else if (_energy_points <= 0)
		std::cout << "ClapTrap " << _name << " does not have any energy point to repair itself" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is dead and cannot be repaired" << std::endl;
}

// Getters
unsigned int	ClapTrap::get_hit_points(void)
{
	return (this->_hit_points);
}

unsigned int	ClapTrap::get_energy_points(void)
{
	return (this->_energy_points);
}

std::string		ClapTrap::get_name(void)
{
	return (this->_name);
}

void	ClapTrap::display_hit_points()
{
	std::cout << "[HIT POINTS]: "<< this->_hit_points << std::endl;
}

void	ClapTrap::display_energy_points()
{
	std::cout << "[ENERGY POINTS]: "<< this->_energy_points << std::endl;
}

void	ClapTrap::display_attack_damage()
{
	std::cout << "[ATTACK DAMAGE]: "<< this->_attack_damage << std::endl;
}

void	ClapTrap::display_all()
{
	std::cout << get_name() << ": ";
	std::cout << "[HIT POINTS]: "<< this->_hit_points;
	std::cout << " [ENERGY POINTS]: "<< this->_energy_points;
	std::cout << " [ATTACK DAMAGE]: "<< this->_attack_damage << std::endl;
}
