/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 12:47:42 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"

void	test_shrubbery()
{
	std::cout << std::endl << BBLUE << "-------------- SHRUBBERY --------------" << WHITE << std::endl;
	std::cout << std::endl << BLUE << "--- EXECUTION WORKS ---" << WHITE << std::endl;
	{	
		ShrubberyCreationForm	form("test");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 137);
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
	}

	std::cout << std::endl << BLUE << "--- FAIL EXECUTION: GRADE NOK ---" << WHITE << std::endl;
	{	
		ShrubberyCreationForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 138);
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
	}

	std::cout << std::endl << BLUE << "--- FAIL: FORM NOT SIGNED  ---" << WHITE << std::endl;
	{	
		ShrubberyCreationForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 137);
		bureaucrat.executeForm(form);
	}
}

void	test_robotomy()
{
	std::cout << std::endl << BBLUE << "-------------- ROBOTOMY --------------" << WHITE << std::endl;
	std::cout << std::endl << BLUE << "--- EXECUTION WORKS ---" << WHITE << std::endl;
	{	
		RobotomyRequestForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 1);
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
		bureaucrat.executeForm(form);
	}

	std::cout << std::endl << BLUE << "--- FAIL: GRADE NOK ---" << WHITE << std::endl;
	{	
		RobotomyRequestForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 50);
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);

	}

	std::cout << std::endl << BLUE << "--- FAIL: FORM NOT SIGNED  ---" << WHITE << std::endl;
	{	
		RobotomyRequestForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 1);
		bureaucrat.executeForm(form);
	}
}

void	test_presidential()
{
	std::cout << std::endl << BBLUE << "-------------- PRESIDENTIAL --------------" << WHITE << std::endl;
	std::cout << std::endl << BLUE << "--- EXECUTION WORKS ---" << WHITE << std::endl;
	{	
		PresidentialPardonForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 1);
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
	}

	std::cout << std::endl << BLUE << "--- FAIL: GRADE NOK ---" << WHITE << std::endl;
	{	
		PresidentialPardonForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 10);
		bureaucrat.signForm(form);
		std::cout << form;
		bureaucrat.executeForm(form);
	}

	std::cout << std::endl << BLUE << "--- FAIL: FORM NOT SIGNED  ---" << WHITE << std::endl;
	{	
		PresidentialPardonForm	form("home");
		std::cout << form;

		Bureaucrat				bureaucrat("Bob", 1);
		bureaucrat.executeForm(form);
	}
}

void	test_polymorphism(void)
{
	std::cout << std::endl << BBLUE << "-------------- POLYMORPHISM --------------" << WHITE << std::endl;
	std::cout << std::endl << BLUE << "--- EXECUTES PRESIDENTIAL ---" << WHITE << std::endl;
	{	
		AForm*	form = new PresidentialPardonForm("home");
		std::cout << *form;

		Bureaucrat				bureaucrat("Bob", 1);
		bureaucrat.signForm(*form);
		std::cout << *form;
		bureaucrat.executeForm(*form);
		delete form;
	}
}

int main(void)
{
	test_shrubbery();
	std::cout << std::endl;
	test_robotomy();
	std::cout << std::endl;
	test_presidential();
	test_polymorphism();
}
