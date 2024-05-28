/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 21:02:09 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/28 16:14:13 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM_HPP__
# define __AFORM_HPP__

# include <iostream>
# include <string>
# include <exception>
# include <stdbool.h>
# include <iostream>
# include <fstream>
# include <stdexcept>

# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		const int			_gradeSign;
		const int			_gradeExec;
		bool				_signed;
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& src);
		virtual ~AForm();

		AForm&			operator=( AForm const & rhs );

		std::string	getName() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		bool		getSigned() const;

		void			beSigned(Bureaucrat& bureaucrat);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void			execution_rights(Bureaucrat const &executor) const;

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

		class ExecutionDeniedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& buro);


#endif
