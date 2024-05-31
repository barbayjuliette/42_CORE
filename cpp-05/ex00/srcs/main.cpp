/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:44:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 12:15:58 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"

void	test_happy(void)
{
	std::cout << BLUE << "--- HAPPY TEST: Everything works ---" << WHITE << std::endl;
	try {
		Bureaucrat bureaucrat("Brian", 25);
		bureaucrat.increment_grade();
		bureaucrat.increment_grade();
		bureaucrat.decrement_grade();
		bureaucrat.decrement_grade();
		bureaucrat.decrement_grade();
	} catch (std::exception & e){
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << std::endl;
	}
	return ;
}

void	catch_exception(void)
{
	std::cout << std::endl << BLUE << "--- EXCEPTION TEST: Both exceptions should be caught---" << WHITE << std::endl;
	try {
		Bureaucrat bureaucrat("Brian", 2);
		bureaucrat.increment_grade();
		bureaucrat.increment_grade();
	} catch (std::exception & e){
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << std::endl;
	}
	
	try {
		Bureaucrat test("Bob", 148);
		test.decrement_grade();
		test.decrement_grade();
		test.decrement_grade();
	} catch (std::exception & e){
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << std::endl;
	}
	return ;
}

void	exception_creation(void)
{
	std::cout << std::endl << BLUE << "--- EXCEPTION CREATION: Created with out of bound value ---" << WHITE << std::endl;
	try {
		Bureaucrat bureaucrat("Brian", 151);
		bureaucrat.increment_grade();
		bureaucrat.increment_grade();
	} catch (std::exception & e){
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << std::endl;
	}
}

void	test_copy_const(void)
{
	std::cout << std::endl << BLUE << "--- COPY CONSTRUCTOR---" << WHITE << std::endl;
	try {
		Bureaucrat	bureaucrat("Brian", 68);
		Bureaucrat	copy(bureaucrat);
		copy.increment_grade();
	} catch (std::exception & e){
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << std::endl;
	}
}

void	test_assignment_op(void)
{
	std::cout << std::endl << BLUE << "--- ASSIGNMENT OPERATOR ---" << WHITE << std::endl;
	try {
		Bureaucrat	bureaucrat("Brian", 68);
		Bureaucrat	copy;
		copy = bureaucrat;
		copy.increment_grade();
	} catch (std::exception & e){
		std::cerr << RED << "Exception caught: " << e.what() << WHITE << std::endl;
	}
}

int main(void)
{
	test_happy();
	catch_exception();
	exception_creation();
	test_copy_const();
	test_assignment_op();
}
