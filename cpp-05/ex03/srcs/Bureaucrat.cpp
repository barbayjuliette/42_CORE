/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:39:42 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 12:55:43 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
	std::cout << "Created bureaucrat " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Created bureaucrat " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Copy constructed bureaucrat " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructed bureaucrat " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	Bureaucrat::increment_grade()
{
	if (_grade <= 1)
		throw (Bureaucrat::GradeTooHighException());
	this->_grade--;
	std::cout << this->getName() << " incremented to grade " << this->getGrade() << std::endl;
}

void	Bureaucrat::decrement_grade()
{
	if (_grade >= 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade++;
	std::cout << this->getName() << " decremented to grade " << this->getGrade() << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "Grade too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Grade too Low";
}

void	Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << "Bureaucrat " << this->getName() << " signed form " << form.getName() << std::endl;
	}
	catch (std::exception& e){
		std::cout << RED << this->getName() << " could not sign form " << form.getName();
		std::cout << ". Reason: " << e.what() << WHITE << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "Bureaucrat " << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << '\n';
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& buro)
{
	os << buro.getName() << ", bureaucrat grade " << buro.getGrade() << std::endl;
	return (os);
}
