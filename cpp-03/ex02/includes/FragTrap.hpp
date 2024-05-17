/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:57:07 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 21:05:18 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		// Default constructor + name
		FragTrap(void);
		FragTrap(std::string name);

		// Copy constructor
		FragTrap(const FragTrap& clap);
		
		// Assignment operator
		FragTrap&	operator=(FragTrap const& clap);

		// Destructor
		~FragTrap(void);

		// Member functions
		void	highFivesGuys(void);
};

#endif
