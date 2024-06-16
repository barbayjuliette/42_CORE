/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:54 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/16 18:58:42 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RNP_HPP__
# define __RNP_HPP__

#include <iostream>
#include <string>
#include <cstdlib>
#include <string> 
#include <sstream>
#include <stack>
#include <iomanip>
#include <cstdlib>

#define WHITE "\e[0;97m"
#define RED "\e[31m"


class RNP
{
	private:
		RNP(void);
		std::string	exp;
	public:
		// Constructors
		RNP(std::string exp);

		// Copy constructor
		RNP(const RNP& copy);
		
		// Assignment operator
		RNP&	operator=(RNP const& rhs);

		// Destructor
		~RNP(void);
		
		// Member functions
		void	process_stack();
		void	check_errors();
		void	calculate(char operation, std::stack<std::string> & stack);
		bool	isoperator(char c);
};

#endif