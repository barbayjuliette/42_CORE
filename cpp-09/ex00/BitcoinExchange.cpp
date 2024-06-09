/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/09 22:32:59 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string	trim_spaces(std::string str)
{
	int	start = 0;
	int	end = str.length() - 1;

	while (start <= end && str[start] == ' ')
		start++;
	while (end > start && str[end] == ' ')
		end--;

	return (str.substr(start, end - start + 1));
}

// Constructors
BitcoinExchange::BitcoinExchange(void)
{
	// Initialize database
	std::ifstream		csv("data.csv");
	std::string			line;
	std::string			key;
	float				value;
	std::stringstream	stream;

	if (!csv.is_open())
	{
		std::cerr << "Error creating the database from file: \n";
		perror("");
		return ;
	}
	while (getline(csv, line))
	{
		size_t	pos;;
		pos = line.find(",");
		if (pos == std::string::npos || pos == 0)
		{
			std::cerr << "Error in database";
			return ;
		}
		key = trim_spaces(line.substr(0, pos));
		line.erase(0, pos + 1);
		stream << line;
		stream >> value;
		stream.clear();
		data[key] = value;
		// std::cout << "Key: *" << key << "*" << std::endl;
		// std::cout << "Value: *" << value << "*" << std::endl;
		// std::cout << "data[key]: " << data[key] << std::endl << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	(void)copy;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
	// Delete database
}

// Assignment operator
BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	(void)rhs;
	return (*this);
}

bool	is_thirty_days(int month)
{
	int thirty_days[] = {4, 6, 9, 11};

	int	i = 0;
	int size = sizeof(thirty_days) / sizeof(thirty_days[0]);
	while (i < size)
	{
		if (month == thirty_days[i])
			return (true);
		i++;
	}
	return (false);
}

std::string	get_previous_day(std::string date)
{
	int	day = atoi(date.substr(8, 2).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	year = atoi(date.substr(0, 4).c_str());
	std::stringstream	stream;

	day--;
	if (day <= 0)
	{
		month--;
		if (month <= 0)
		{
			month = 12;
			year--;
			day = 31;
		}
		if (month == 2)
			day = 28;
		else if (is_thirty_days(month))
			day = 30;
		else
			day = 31;
	}

	stream << std::setw(4) << std::setfill('0') << year << '-'
			<< std::setw(2) << std::setfill('0') << month << '-'
			<< std::setw(2) << std::setfill('0') << day;

	stream >> date;
	return (date);
}

void	BitcoinExchange::calculate_exchange(std::string line)
{
	size_t				pos;
	std::string			date;
	float				value;
	std::stringstream	stream;
	// float				rate;
	// float				result;

	pos = line.find("|");
	if (pos == std::string::npos || pos == 0)
	{
		std::cerr << "Error: Bad format";
		return ;
	}
	date = trim_spaces(line.substr(0, pos));
	line.erase(0, pos + 1);

	stream << line;
	stream >> value;
	stream.clear();
	// rate = data[date];
	// result = value * rate;

	// std::map<std::string, float>::iterator it = data.find(date);

	// while (data.find(date) != data.end())
	// {
	// 	date = get_previous_day(date);
	// }
	std::cout << "Date:" << date << std::endl;
	date = get_previous_day(date);
	std::cout << "Date: " << date << std::endl;


	// if (data.find(date) != data.end())
	// 	std::cout << "Found, value is: " << data[date] << std::endl;
	// else
	// 	std::cout << "Value not found" << std::endl;
	// std::cout << date << " => " << value << " = " << result << std::endl;
	// std::cout << "Data not found ";
	// rate = data[date];
	// result = value * rate;

	// std::cout << "Rate from data[]: " << rate << std::endl;
	// std::cout << "Value from input: *" << value << "*" << std::endl;
	// std::cout << "Date from input: *" << date << "*" << std::endl << std::endl;
	// std::cout << "Result: " << result << std::endl << std::endl;
}