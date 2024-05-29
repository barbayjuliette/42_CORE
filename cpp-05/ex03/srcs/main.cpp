/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 16:48:11 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"
# include "../includes/Form.hpp"
# include "../includes/Intern.hpp"
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"


int main(void)
{
	Intern 		someRandomIntern;
	Bureaucrat	bureaucrat("Bob", 5);
	Form* 		rrf;
	
	std::cout << BLUE << "--- WRONG FORM - ERROR ---" << WHITE << std::endl;
	try
	{
		rrf = someRandomIntern.makeForm("jyfk", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception found: " << e.what() << '\n' << WHITE;
	}

	std::cout << std::endl << BLUE << "--- EXECUTION WORKS ---" << WHITE << std::endl;
	try
	{
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		bureaucrat.signForm(*rrf);
		bureaucrat.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception found: " << e.what() << '\n' << WHITE;
	}
}
