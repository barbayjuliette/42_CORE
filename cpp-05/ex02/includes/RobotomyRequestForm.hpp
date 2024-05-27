/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:35:30 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/27 21:36:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name, int gradeSign, int gradeExec);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		RobotomyRequestForm&			operator=( RobotomyRequestForm const & rhs );

		void	execute(Bureaucrat const &executor);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
