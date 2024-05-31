/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:53:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 12:22:36 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Unknown"), _gradeSign(1), _gradeExec(1), _signed(false)
{
	std::cout << "Created Form " << this->getName() << std::endl;
}

Form::Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw (Form::GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw (Form::GradeTooLowException());
	std::cout << "Created Form " << this->getName() << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec), _signed(src._signed)
{
	std::cout << "Copy constructed Form " << this->getName() << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Destructed Form " << this->getName() << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &	Form::operator=( Form const & rhs )
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *Form::GradeTooHighException::what() const throw ()
{
	return "Grade too High";
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return "Grade too Low";
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw (Form::GradeTooLowException());
	this->_signed = true;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName() const
{
	return (this->_name);
}

int	Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int	Form::getGradeExec() const
{
	return (this->_gradeExec);
}

bool	Form::getSigned() const
{
	return (this->_signed);
}

/*
** --------------------------------- OTHERS ---------------------------------
*/

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << GREEN << "Form " << form.getName() << std::endl;
	os << "--- Grade to sign:" << form.getGradeSign() << std::endl;
	os << "--- Grade to execute:" << form.getGradeExec() << std::endl;
	os << "--- Signed: " << (form.getSigned() ? "Yes" : "No") << WHITE << std::endl;
	return (os);
}
