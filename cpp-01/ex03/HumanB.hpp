/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:52:25 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/22 23:06:54 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*_weapon;
		std::string	_name;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon& weapon);
};
