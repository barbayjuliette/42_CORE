/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:43:55 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 22:45:33 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		// Default constructor + name
		ScavTrap(void);
		ScavTrap(std::string name);

		// Copy constructor
		ScavTrap(const ScavTrap& clap);
		
		// Assignment operator
		ScavTrap&	operator=(ScavTrap const& clap);

		// Destructor
		~ScavTrap(void);

		// Member functions
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
