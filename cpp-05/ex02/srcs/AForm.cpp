/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:01:21 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/27 21:01:49 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include <stdexcept>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("Unknown"), _gradeSign(1), _gradeExec(1), _signed(false)
{
	std::cout << "Created AForm " << this->getName() << std::endl;
}

AForm::AForm(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeSign(gradeSign), _gradeExec(gradeExec), _signed(false)
{
	if (_gradeSign < 1 || _gradeExec < 1)
		throw (AForm::GradeTooHighException());
	else if (_gradeSign > 150 || _gradeExec > 150)
		throw (AForm::GradeTooLowException());
	std::cout << "Created AForm " << this->getName() << std::endl;
}

AForm::AForm(const AForm& src) : _name(src._name), _gradeSign(src._gradeSign), _gradeExec(src._gradeExec), _signed(src._signed)
{
	std::cout << "Copy constructed AForm " << this->getName() << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << "Destructed AForm " << this->getName() << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &	AForm::operator=( AForm const & rhs )
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_signed = rhs._signed;
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

const char *AForm::GradeTooHighException::what() const throw ()
{
	return "Grade too High";
}

const char *AForm::GradeTooLowException::what() const throw ()
{
	return "Grade too Low";
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeSign)
		throw (AForm::GradeTooLowException());
	this->_signed = true;
	std::cout << "AForm " << this->getName() << " signed!" << std::endl;

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	AForm::getName() const
{
	return (this->_name);
}

int	AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int	AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

bool	AForm::getSigned() const
{
	return (this->_signed);
}

/*
** --------------------------------- OTHERS ---------------------------------
*/

std::ostream& operator<<(std::ostream& os, const AForm& AForm)
{
	os << GREEN << "AForm " << AForm.getName() << std::endl;
	os << "--- Grade to sign:" << AForm.getGradeSign() << std::endl;
	os << "--- Grade to execute:" << AForm.getGradeExec() << std::endl;
	os << "--- Signed: " << (AForm.getSigned() ? "Yes" : "No") << WHITE << std::endl;
	return (os);
}
