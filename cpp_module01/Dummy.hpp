/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:15 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 15:11:36 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class Dummy : public ATarget
{
	protected:
		std::string	_type;
	public:
		Dummy();
		Dummy(const Dummy& obj);
		Dummy& operator=(Dummy const & rhs);
		~Dummy();

		ATarget*	clone() const;
		
		// Getters
		const std::string &	getType() const;
};