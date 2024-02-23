/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 23:52:17 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/22 22:38:35 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		&_weapon;
		std::string	_name;
	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);
		void attack(void);
};
