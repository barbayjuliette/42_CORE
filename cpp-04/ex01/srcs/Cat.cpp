/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:11:45 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 18:47:14 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called 🐱" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& src): Animal(src), _brain(new Brain())
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*(this->_brain) = *(src.get_brain());
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &	Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat assignment operator called" << std::endl;
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

void	Cat::makeSound() const
{
	std::cout << "Meow " << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Brain*		Cat::get_brain() const
{
	return (this->_brain);
}

/* ************************************************************************** */