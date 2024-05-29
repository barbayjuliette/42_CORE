/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:38:17 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/29 17:03:50 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
# define __BUREAUCRAT_HPP__

# include <iostream>
# include <string>
# include <exception>

#define WHITE "\e[97m"
#define RED "\e[31m"
#define GREEN "\e[32m"
#define BLUE "\e[0;36m"

class Bureaucrat
{
	protected:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		~Bureaucrat();

		Bureaucrat&			operator=( Bureaucrat const & rhs );

		std::string	getName() const;
		int			getGrade() const;

		void	increment_grade();
		void	decrement_grade();

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& buro);

#endif
