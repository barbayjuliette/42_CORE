/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:28:36 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 16:17:59 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
# define __SHRUBBERYCREATIONFORM_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>

# include "./Form.hpp"
# include "./Bureaucrat.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private:
		const std::string	_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&			operator=( ShrubberyCreationForm const & rhs );

		void		execute(Bureaucrat const &executor) const;
		std::string	getTarget(void) const;
};

Form	*create_shrub(std::string target);

#endif
