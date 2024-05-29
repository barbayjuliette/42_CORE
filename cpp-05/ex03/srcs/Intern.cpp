/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:50:38 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 16:42:45 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"
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
	*this = src;
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
	(void)rhs;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	Form	*(*ptr_shrub)(std::string) = &create_shrub;
	Form	*(*ptr_robo)(std::string) = &create_robot;
	Form	*(*ptr_presi)(std::string) = &create_presi;

	Form	*(*ptr_forms[3])(std::string) = { ptr_shrub, ptr_robo, ptr_presi };
	int	i = 0;

	while (i < 3)
	{
		if (name == forms[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return ((*ptr_forms[i])(target));
		}
		i++;
	}
	throw (Form::FormDoesNotExist());
	return (NULL);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
