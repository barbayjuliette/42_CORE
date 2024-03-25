/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_helpers.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:17:14 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/25 17:17:16 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../phone_book.hpp"

std::string	add_data_contact(std::string prompt)
{
	std::string	data;

	std::cout << prompt;
	std::getline(std::cin, data);	
	while (data.length() == 0 || std::cin.eof() || std::cin.fail())
	{
		if (std::cin.fail() || std::cin.eof())
			exit(0);
		std::cout << "Please give a valid " << prompt;
		std::getline(std::cin, data);	
	}
	return data;
}
