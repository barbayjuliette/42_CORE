/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:06:09 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 15:02:12 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ATarget
{
	protected:
		std::string	_type;
	public:
		ATarget();
		ATarget(const ATarget& obj);
		ATarget& operator=(ATarget const & rhs);
		ATarget(std::string type);
		virtual ~ATarget();

		virtual ATarget*	clone() const = 0;
		void	getHitBySpell(const ASpell & spell);
		
		// Getters
		const std::string &	getType() const;
};