/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:18 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 15:12:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fwoosh.hpp"

// Construction
Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{
	std::cout << "Default constructor Fwoosh called\n";
}

Fwoosh::Fwoosh(const Fwoosh& obj) : ASpell(obj.getName(), obj.getEffects())
{
	std::cout << "Copy constructor Fwoosh called\n";
}

Fwoosh& Fwoosh::operator=(Fwoosh const & rhs)
{
	if (this != &rhs)
		ASpell::operator=(rhs);
	return (*this);
}

Fwoosh::~Fwoosh()
{
	std::cout << _name << ": My Fwoosh job here is done!" << std::endl;
}


ASpell*	Fwoosh::clone() const
{
	Fwoosh*	copy = new Fwoosh();
	return (copy);
}
