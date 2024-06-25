/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 11:31:59 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/25 16:02:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

// Construction
Warlock::Warlock()
{
	std::cout << "Default constructor called\n";
}

Warlock::Warlock(const Warlock& obj) : _name(obj.getName()), _title(obj.getTitle())
{
	std::cout << "Copy constructor called\n";
}


Warlock::Warlock(std::string name, std::string title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day" << std::endl;
}

Warlock& Warlock::operator=(Warlock const & rhs)
{
	if (this != &rhs)
	{
		this->_title = rhs.getTitle();
		this->_name = rhs.getName();
	}
	return (*this);
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
}

// Member functions
void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		if (_spells.find(spell->getName()) == _spells.end())
			_spells[spell->getName()] = spell->clone()
	}
}

void	Warlock::forgetSpell(std::string spell_name)
{

	std::map<std::string, ASpell *>::iterator	it;
	it = _spells.find(spell_name);

	if (it != _spells.end())
		_spells.erase(it);
}

void	Warlock::launchSpell(std::string spell_name, const ATarget & target)
{
	std::map<std::string, ASpell *>::iterator	it;
	it = _spells.find(spell_name);
	
}

// GETTERS
const std::string &	Warlock::getName() const
{
	return (_name);
}

const std::string &	Warlock::getTitle() const
{
	return (_title);
}

// SETTERS
void	Warlock::setTitle(const std::string & title)
{
	this->_title = title;
}