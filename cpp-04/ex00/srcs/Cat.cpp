/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 17:11:45 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 18:19:45 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat(): Animal()
{
	type = "Cat";
	std::cout << "Cat constructor called 🐱" << std::endl;
}

Cat::Cat(const Cat& src): Animal(src)
{
	std::cout << "Cat Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &	Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &rhs)
		Animal::operator=(rhs);
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


/* ************************************************************************** */