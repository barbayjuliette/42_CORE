/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:57:33 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 18:35:14 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include "../includes/WrongAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat(): WrongAnimal()
{
	type = "Wrong Cat";
	std::cout << "Wrong Cat constructor called 🐆" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src ) : WrongAnimal(src)
{
	std::cout << "Wrong Cat Copy constructor called" << std::endl;
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
	std::cout << "Wrong Cat assignment operator called" << std::endl;
	if (this != &rhs)
		WrongAnimal::operator=(rhs);
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