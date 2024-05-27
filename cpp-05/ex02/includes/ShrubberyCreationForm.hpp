/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:28:36 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/27 21:33:19 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name, int gradeSign, int gradeExec);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&			operator=( ShrubberyCreationForm const & rhs );

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
