/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:03:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/30 18:48:33 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

# include <iostream>
# include <string>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include "print.cpp"

class ScalarConverter
{
	protected:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();
		ScalarConverter&			operator=( ScalarConverter const & rhs );

	public:
		static void	convert(std::string literal);
};

#endif