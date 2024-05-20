/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:57:11 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 21:10:28 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/ClapTrap.hpp"
#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap("Default", 100, 100, 30)
{
	std::cout << get_name() << " FragTrap created with default constructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << get_name() << " FragTrap created!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << get_name() << " FragTrap destroyed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& clap): ClapTrap(clap)
{
	std::cout << "Copy constructor Scav called" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const& clap)
{
	ClapTrap::operator=(clap);
	std::cout << "Assignment operator Scav called" << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << " says: HIGH FIVE GUYS!!!" << std::endl;
}
