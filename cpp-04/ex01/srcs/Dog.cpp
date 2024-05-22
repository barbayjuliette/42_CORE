/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:11:17 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 18:32:44 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog(): Animal()
{
	std::cout << "Dog constructor called 🐶" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src), _brain(new Brain())
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*(this->_brain) = *(src.get_brain());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog&	Dog::operator=( Dog const& rhs )
{
	std::cout << "Dog assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Animal::operator=(rhs);
		*(this->_brain) = *(rhs.get_brain());
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain*		Dog::get_brain() const
{
	return (this->_brain);
}

/* ************************************************************************** */