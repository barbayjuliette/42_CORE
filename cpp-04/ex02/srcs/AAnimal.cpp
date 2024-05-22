/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:17 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 18:29:19 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
	type = "Unknown Animal";
	std::cout << "Animal constructor called 👻" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src )
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal&		AAnimal::operator=( AAnimal const & rhs )
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &rhs)
		this->type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	AAnimal::makeSound() const
{
	std::cout << "Unknown sound" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AAnimal::getType() const
{
	return (this->type);
}

/* ************************************************************************** */