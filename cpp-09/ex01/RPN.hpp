/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:21:54 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/10 21:48:19 by jbarbay          ###   ########.fr       */
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

void	calculate(char operation, std::stack<std::string> & stack);
bool	isoperator(char c);

class RNP
{
	public:
		std::string	exp;

		// Constructors
		RNP(void);
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
};

#endif