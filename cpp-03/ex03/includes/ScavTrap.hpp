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
		ScavTrap(void); // Default constructor
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& scav); // copy constructor
		~ScavTrap(void);
		void	operator=(ScavTrap const& scav); // Assignment operator
		void	guardGate();
		void	attack(const std::string& target);
};

#endif
