/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:07 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/10 18:09:18 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <exception>

std::string		trim_spaces(std::string str);
std::string		get_previous_day(std::string date);
bool			is_thirty_days(int month);
bool			is_leap_year(int	year);
std::string		get_previous_day(std::string date);
std::string 	formatNumber(double value);
void			check_valid_date(std::string	date);


class BitcoinExchange
{
	private:


	public:
		std::map<std::string, float>	data;
		// Constructors
		BitcoinExchange(void);

		// Copy constructor
		BitcoinExchange(const BitcoinExchange& copy);
		
		// Assignment operator
		BitcoinExchange&	operator=(BitcoinExchange const& rhs);

		// Destructor
		~BitcoinExchange(void);
		
		void	calculate_exchange(std::string line);
};

#endif