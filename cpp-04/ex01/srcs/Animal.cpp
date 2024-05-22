/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:17 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 13:33:01 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	type = "Unknown Animal";
	std::cout << "Animal constructor called 👻" << std::endl;
}

Animal::Animal( const Animal & src )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal&		Animal::operator=( Animal const & rhs )
{
	std::cout << "Animal assignment operator called" << std::endl;
	this->type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Animal::makeSound() const
{
	std::cout << "Unknown sound" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Animal::getType() const
{
	return (this->type);
}

/* ************************************************************************** */