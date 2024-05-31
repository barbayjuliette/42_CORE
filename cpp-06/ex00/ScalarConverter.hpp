/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:03:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 17:33:27 by jbarbay          ###   ########.fr       */
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

int		get_precision_float(std::string lit);
int		get_precision_double(std::string lit);
int		is_int(std::string lit);
int		is_double(std::string lit);
void	special_values(std::string	lit);
void	handle_float(float num, int precision);
int 	is_displayable(int c);
void	handle_int(int num);
void	handle_double(double num, int precision);
void	handle_char(char c);

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