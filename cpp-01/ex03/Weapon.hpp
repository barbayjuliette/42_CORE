/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:14:54 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/21 13:50:44 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(std::string type);
		Weapon(void);
		~Weapon(void);
		const std::string&	getType(void) const;
		void	setType(std::string type);
};

#endif
