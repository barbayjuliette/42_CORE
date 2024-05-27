/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:28:30 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/27 21:35:05 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
# define __PRESIDENTIALPARDONFORM_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string name, int gradeSign, int gradeExec);
		PresidentialPardonForm(const PresidentialPardonForm& src);
		~PresidentialPardonForm();

		PresidentialPardonForm&			operator=( PresidentialPardonForm const & rhs );

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
