/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:22 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 15:08:24 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	protected:
	public:
		Fwoosh();
		Fwoosh& operator=(Fwoosh const & rhs);
		~Fwoosh();

		ASpell*	clone() const;
};