/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:57:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/21 20:18:44 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongAnimal::WrongAnimal()
{
	type = "Wrong Animal";
	std::cout << "Wrong Animal constructor called 🧌" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	std::cout << "Wrong Animal Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wrong Animal destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongAnimal&	WrongAnimal::operator=( WrongAnimal const & rhs )
{
	std::cout << "Wrong Animal assignment operator called" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string	WrongAnimal::getType() const
{
	return (this->type);
}

/* ************************************************************************** */