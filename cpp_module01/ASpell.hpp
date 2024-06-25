/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:00 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 14:36:32 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ASpell
{
	protected:
		std::string	_name;
		std::string	_effects;
	public:
		ASpell();
		ASpell(const ASpell& obj);
		ASpell& operator=(ASpell const & rhs);
		ASpell(std::string name, std::string effect);
		virtual ~ASpell();

		virtual ASpell*	clone() const = 0;
		
		// Getters
		const std::string	getName() const;
		const std::string	getEffects() const;
};