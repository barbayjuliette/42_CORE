/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:35:30 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 16:56:15 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
# define __ROBOTOMYREQUESTFORM_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>
# include <iostream>
# include <fstream>
# include <cstdlib>

# include "./Bureaucrat.hpp"
# include "./AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& src);
		~RobotomyRequestForm();

		RobotomyRequestForm&			operator=( RobotomyRequestForm const & rhs );

		void		execute(Bureaucrat const &executor) const;
		std::string	getTarget(void) const;
};

#endif
