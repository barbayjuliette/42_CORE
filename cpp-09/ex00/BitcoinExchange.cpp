/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:03 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/16 18:48:18 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Constructors
BitcoinExchange::BitcoinExchange(void)
{
	std::ifstream		csv("data.csv");
	std::string			line;
	std::string			key;
	double				value;
	std::stringstream	stream;

	if (!csv.is_open())
	{
		std::cerr << "Error creating the database from file: \n";
		perror("");
		return ;
	}
	getline(csv, line);
	if (line != "date,exchange_rate")
		throw (std::runtime_error("Wrong format database"));
	while (getline(csv, line))
	{
		size_t	pos;;
		pos = line.find(",");
		if (pos == std::string::npos || pos == 0)
			throw (std::runtime_error("Wrong format database"));
		key = trim_spaces(line.substr(0, pos));
		line.erase(0, pos + 1);
		stream << line;
		stream >> value;
		data[key] = value;
		if (stream.fail())
			throw (std::runtime_error("Wrong format database"));
		stream.clear();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) : data(copy.data)
{
	(void)copy;
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{

}

// Assignment operator
BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
	if (this != &rhs)
		this->data = rhs.data;
	return (*this);
}

// Member functions
void	BitcoinExchange::calculate_exchange(std::string line)
{
	size_t				pos;
	std::string			date;
	std::string			date_copy;
	double				value;
	std::stringstream	stream;
	double				rate;
	double				result;

	pos = line.find("|");
	if (pos == std::string::npos || pos == 0)
		throw (std::runtime_error("Bad input => " + line));
	date = trim_spaces(line.substr(0, pos));
	line.erase(0, pos + 1);
	line = trim_spaces(line);

	if (!isdigit(line[0]))
		throw (std::runtime_error("Value not valid: " + line));
	stream << line;
	stream >> value;

	if (value < 0)
		throw (std::runtime_error("not a positive number"));
	else if (value > 1000)
		throw (std::runtime_error("too large a number"));
	
	stream.clear();
	check_valid_date(date);
	date_copy = date;
	while (data.find(date) == data.end())
	{
		date = get_previous_day(date);
	}
	rate = data[date];
	result = value * rate;
	std::cout << date_copy << " => " << value << " = " << formatNumber(result) << std::endl;
}

// Helpers

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

bool	is_leap_year(int	year)
{
	if ((year % 4 == 0) && !(year % 100 == 0))
		return (true);
	else if ((year % 100 == 0) && (year % 400 == 0))
		return (true);
	return (false);
}

void	check_valid_date(std::string	date)
{
	size_t	i = 0;
	while (i < date.length())
	{
		if (i == 4 || i == 7)
		{
			if (date[i] != '-')
				throw (std::runtime_error("Date not valid: " + date));
		}
		else if (!isdigit(date[i]))
			throw (std::runtime_error("Date not valid: " + date));
		i++;
	}
	int	day = atoi(date.substr(8, 2).c_str());
	int	month = atoi(date.substr(5, 2).c_str());
	int	year = atoi(date.substr(0, 4).c_str());

	if (month > 12 || month <= 0)
		throw (std::runtime_error("Date not valid: " + date));
	else if (day <= 0)
		throw (std::runtime_error("Date not valid: " + date));
	else if (is_thirty_days(month) && day > 30)
		throw (std::runtime_error("Date not valid: " + date));
	else if (month == 2 && is_leap_year(year) && day > 29)
		throw (std::runtime_error("Date not valid: " + date));
	else if (month == 2 && day > 28)
		throw (std::runtime_error("Date not valid: " + date));
	else if (day > 31)
		throw (std::runtime_error("Date not valid: " + date));

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
		{
			if (is_leap_year(year))
				day = 29;
			else
				day = 28;
		}
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

std::string formatNumber(double value)
{
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(5) << value;
	std::string str = oss.str();

	size_t pos = str.find_last_not_of('0');
	if (pos != std::string::npos) {
		if (str[pos] == '.')
			pos--;
		str.erase(pos + 1);
	}

	return (str);
}

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
