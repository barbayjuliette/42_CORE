/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:08:42 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 16:22:18 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
# include <iostream>
# include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("none")
{
	std::cout << "Created ShrubberyCreationForm with target " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "Created ShrubberyCreationForm with target " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : Form(src), _target(src._target)
{
	std::cout << "Copy constructed ShrubberyCreationForm with target " << this->getTarget() << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructed ShrubberyCreationForm " << this->getTarget() << std::endl;
}


ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &rhs)
	{
		Form::operator=(rhs);
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

	std::string tree_1 = "      \n\
	                       _-_\\\n\
                            /~~   ~~\\\n\
                         /~~         ~~\\\n\
                         {             }\n\
                          \\ _-     -_ /\n\
                           ~  \\\\ //  ~\n\
                        _- -   | | _- _\n\
                          _ -  | |   -_\n\
                              // \\\\\n";
	std::string	tree_2 = "         \n\
	                         ###\n\
                                #o###\n\
                              #####o###\n\
                             #o#\\#|#/###\n\
                              ###\\|/#o#\n\
                               # }|{  #\n\
                                 }|{\n";
    std::string	tree_3 = "      \n\
  ,d\n\
  88\n\
MM88MMM 8b,dPPYba,  ,adPPYba,  ,adPPYba,\n\
  88    88P'   \"Y8 a8P_____88 a8P_____88\n\
  88    88         8PP\"\"\"\"\"\"\" 8PP\"\"\"\"\"\"\"\n\
  88,   88         \"8b,   ,aa \"8b,   ,aa\n\
  \"Y888 88          `\"Ybbd8\"'  `\"Ybbd8\"' \n";


		this->execution_rights(executor);
		std::ofstream	file((_target + "_shrubbery").c_str());
		if (!file.is_open())
			throw (std::runtime_error("Could not create file"));
		file << tree_1 << tree_2 << tree_3;
		file.close();
}

Form	*create_shrub(std::string target)
{
	Form* form = new ShrubberyCreationForm(target);
	return (form);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}