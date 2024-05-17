/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:23:20 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 22:30:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		// Default constructor + name
		DiamondTrap(void);
		DiamondTrap(std::string name);

		// Copy constructor
		DiamondTrap(const DiamondTrap& clap);
		
		// Assignment operator
		DiamondTrap&	operator=(DiamondTrap const& clap);

		// Destructor
		~DiamondTrap(void);

		// Member functions
};

#endif
