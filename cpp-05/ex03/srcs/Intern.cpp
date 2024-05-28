/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:50:38 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/27 20:55:30 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
#include "../includes/colors.hpp"
#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "Created Intern " << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Copy constructed Intern " << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "Destructed Intern " << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &	Intern::operator=( Intern const & rhs )
{
	std::cout << "Intern assignment operator called" << std::endl;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Intern::GradeTooHighException::what() const throw ()
{
	return "Grade too High";
}

const char *Intern::GradeTooLowException::what() const throw ()
{
	return "Grade too Low";
}

Form *Intern::makeForm(std::string name, std::string target)
{
	Form form(name);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
