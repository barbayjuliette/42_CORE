/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:31:55 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 12:51:57 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string	_name;
		std::string	_title;
		Warlock();
		Warlock(const Warlock& obj);
		Warlock& operator=(Warlock const & rhs);
	public:
		Warlock(std::string name, std::string title);
		~Warlock();

		void introduce() const;
		
		// Getters
		const std::string &	getName() const;
		const std::string &	getTitle() const;

		// Setters
		void	setTitle(const std::string & title);
};