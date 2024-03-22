/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:16:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/22 11:01:48 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string				_name;
		int			_hit_points;
		int			_energy_points;
		unsigned int			_attack_damage;
	public:
		ClapTrap(void); // Default constructor
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& clap); // copy constructor
		void	operator=(ClapTrap const& clap); // Assignment operator
		~ClapTrap(void);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		unsigned int	get_hit_points();
		unsigned int	get_energy_points();
		std::string		get_name();
};

#endif
