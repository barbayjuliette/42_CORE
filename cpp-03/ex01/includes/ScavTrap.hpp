/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:43:55 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 20:54:44 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Default constructor + name
		ScavTrap(void);
		ScavTrap(std::string name);

		// copy constructor	
		ScavTrap(const ScavTrap& scav);

		// Destructor
		~ScavTrap(void);

		// Assignment operator
		ScavTrap&	operator=(ScavTrap const& scav);

		// Member functions
		void		guardGate();
		void		attack(const std::string& target);
};

#endif
