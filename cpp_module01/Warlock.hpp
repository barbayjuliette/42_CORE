/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:31:55 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 15:57:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>
#include <algorithm>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		std::map<std::string, ASpell *>	_spells;
		Warlock();
		Warlock(const Warlock& obj);
		Warlock& operator=(Warlock const & rhs);
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		// Member functions
		void	introduce() const;
		void	learnSpell(ASpell *spell);
		void	forgetSpell(std::string spell_name);
		void	launchSpell(std::string spell_name, const ATarget & target);
		
		// Getters
		const std::string &	getName() const;
		const std::string &	getTitle() const;

		// Setters
		void	setTitle(const std::string & title);
};