/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:10 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/18 17:33:49 by jbarbay          ###   ########.fr       */
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
	getline(input, line);
	if (line != "date | value")
	{
		std::cerr << "First line must be format: date | value\n";
		return (1);
	}
	while (getline(input, line))
	{
		if (line == "")
			continue ;
		try
		{
			bc.calculate_exchange(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: " << e.what() << '\n';
		}
		
	}
	return (0);
}