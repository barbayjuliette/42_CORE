/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:42:10 by jbarbay           #+#    #+#             */
/*   Updated: 2024/06/09 22:24:16 by jbarbay          ###   ########.fr       */
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

	// BitcoinExchange bc;
	// std::ifstream	input(argv[1]);
	// std::string		line;

	// if (!input.is_open())
	// {
	// 	std::cerr << "Error opening input file: \n";
	// 	perror("");
	// 	return (1);
	// }

	// while (getline(input, line))
	// {
	// 	bc.calculate_exchange(line);
	// }
	(void)argv;
	std::string	date;

	// std::cout << "Date:" << date << std::endl;
	date = get_previous_day("2023-04-01");
	std::cout << "Date:" << date << std::endl;
	return (0);
}