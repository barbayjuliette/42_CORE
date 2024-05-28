/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:44:56 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/27 20:50:12 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

# include "./Form.hpp"

// # include "./Bureaucrat.hpp"

// class Form;

class Intern
{
	private:

	public:
		Intern();
		Intern(const Intern& src);
		virtual ~Intern();

		Intern&			operator=( Intern const & rhs );

		Form *makeForm(std::string name, std::string target);

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

std::ostream& operator<<(std::ostream& os, const Intern& buro);

#endif
