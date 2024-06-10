/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:07 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/10 16:23:32 by jbarbay          ###   ########.fr       */
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

std::string	trim_spaces(std::string str);
std::string	get_previous_day(std::string date);

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

		// float	search(std::string date);
		// float	calculate(float rate, float amount);
		void	calculate_exchange(std::string line);
		void	check_valid_date(std::string	date) const;
};

#endif