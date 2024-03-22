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
		FragTrap(void); // Default constructor
		FragTrap(std::string name);
		FragTrap(const FragTrap& copy); // copy constructor
		~FragTrap(void);
		void	operator=(FragTrap const& copy); // Assignment operator
		void	highFivesGuys(void);
};

#endif
