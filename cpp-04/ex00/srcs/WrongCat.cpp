/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:57:33 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/21 19:35:56 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	type = "Wrong Cat";
	std::cout << "Wrong Cat constructor called 🐆" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal()
{
	std::cout << "Wrong Cat Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "Wrong Cat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat&	WrongCat::operator=( WrongCat const & rhs )
{
	this->type = rhs.getType();
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */