/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 12:30:45 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"
# include "../includes/Form.hpp"

void	test_beSigned(void)
{
	std::cout << BLUE << "--- HAPPY TEST: Bureaucrat signs form ---" << WHITE << std::endl;

	Form form("28C", 150, 150);
	Bureaucrat bureaucrat("Bob", 42);

	std::cout << form;
	form.beSigned(bureaucrat);
	std::cout << form;
}

void	test_signForm(void)
{
	std::cout << std::endl << BLUE << "--- HAPPY TEST: Bureaucrat signs form ---" << WHITE << std::endl;

	Form form("28C", 150, 150);
	Bureaucrat bureaucrat("Bob", 42);

	std::cout << form;
	bureaucrat.signForm(form);
	std::cout << form;
}

void	test_cannot_sign(void)
{

	std::cout  << std::endl << BLUE << "--- EXCEPTION: Bureaucrat cannot sign ---" << WHITE << std::endl;
	Form form("28C", 21, 21);
	Bureaucrat bureaucrat("Bob", 42);
	std::cout << form;
	bureaucrat.signForm(form);
	std::cout << form;
}

void	test_error_creation(void)
{
	std::cout  << std::endl << BLUE << "--- EXCEPTION when creating ---" << WHITE << std::endl;
	try
	{
		Form	form("28C", 151, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Exception caught: "<< e.what() << '\n' << WHITE;
	}
}

int main(void)
{
	test_beSigned();
	test_signForm();
	test_cannot_sign();
	test_error_creation();
}
