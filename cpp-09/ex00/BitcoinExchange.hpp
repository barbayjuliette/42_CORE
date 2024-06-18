/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:07 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/18 17:33:04 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__

#include <map>
#include <fstream>
#include <iostream>
#include <string>
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
		std::map<std::string, float>	data;
		std::string						min_date;

	public:
		// Constructors
		BitcoinExchange(void);

		// Copy constructor
		BitcoinExchange(const BitcoinExchange& copy);
		
		// Assignment operator
		BitcoinExchange&	operator=(BitcoinExchange const& rhs);

		// Destructor
		~BitcoinExchange(void);
		
		void	calculate_exchange(std::string line);
		void	save_data(std::string line, bool min);
		void	is_before(std::string date);
};

#endif