/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 17:07:11 by jbarbay          ###   ########.fr       */
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

	std::cout  << std::endl << BLUE << "--- EXCEPTION: Bureaucrat cannot sign - signForm ---" << WHITE << std::endl;
	Form form("28C", 21, 21);
	Bureaucrat bureaucrat("Bob", 42);
	std::cout << form;
	bureaucrat.signForm(form);
	std::cout << form;
}

int main(void)
{
	test_beSigned();
	test_signForm();
	test_cannot_sign();
}
