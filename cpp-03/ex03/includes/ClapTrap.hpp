/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:16:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 20:30:34 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		int				_hit_points;
		int				_energy_points;
		unsigned int	_attack_damage;
	public:
		// Constructors
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(std::string name, int hit, int energy, int attack);

		// Copy constructor
		ClapTrap(const ClapTrap& clap);
		
		// Assignment operator
		ClapTrap&	operator=(ClapTrap const& clap);

		// Destructor
		~ClapTrap(void);

		// Member functions
		virtual void 	attack(const std::string& target);
		void 			takeDamage(unsigned int amount);
		void 			beRepaired(unsigned int amount);
		unsigned int	get_hit_points();
		unsigned int	get_energy_points();
		std::string		get_name();
		void			display_hit_points();
		void			display_energy_points();
		void			display_attack_damage();
		void			display_all();
};

#endif
