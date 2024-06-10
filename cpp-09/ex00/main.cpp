/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:10 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/10 17:27:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Please only provide one file as argument\n";
		return (1);
	}

	BitcoinExchange bc;
	std::ifstream	input(argv[1]);
	std::string		line;

	if (!input.is_open())
	{
		std::cerr << "Error opening input file: \n";
		perror("");
		return (1);
	}

	while (getline(input, line))
	{
		try
		{
			bc.calculate_exchange(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
		
	}
	// (void)argv;
	// std::string	date = "2019-09-05";
	// std::cout << "Value: " << bc.data[date] << std::endl;
	// std::cout << "Date:" << date << std::endl;
	// date = get_previous_day("2000-08-01");
	// std::cout << "Date:" << date << std::endl;
	return (0);
}