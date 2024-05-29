/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 20:44:56 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 16:43:09 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
# define __INTERN_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>
# include "../includes/ShrubberyCreationForm.hpp"
# include "../includes/PresidentialPardonForm.hpp"
# include "../includes/RobotomyRequestForm.hpp"
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
};

#endif
