/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phone_book_helpers.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:16:50 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/25 17:17:02 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../phone_book.hpp"

void	push_contacts(Contact contacts[])
{
	int i = 0;

	while (i < 7)
	{
		contacts[i] = contacts[i + 1];
		i++;
	}
}

void	choose_index_display(int total_contacts, const Contact contacts[])
{
	int			i;
	std::string	str;

	std::cout << "Enter the index of the contact you want to display\n";
	std::getline(std::cin, str);
	i = std::atoi(str.c_str());

	while (i < 0 || i >= total_contacts || (i == 0 && str != "0"))
	{		
		if (std::cin.fail() || std::cin.eof())
			exit(0);
		std::cout << "Please enter a valid index number\n";
		std::getline(std::cin, str);
		i = std::atoi(str.c_str());
	}
	contacts[i].display_contact();
}

void	display_column(std::string data)
{
	int	len;
	int	spaces;
	int	i = 0;

	len = data.length();

	if (len > 10)
	{
		while (i < 9)
		{
			std::cout << data[i];
			i++;
		}
		std::cout << ".";
	}
	else
	{
		spaces = 10 - len;
		i = 0;
		while (i < spaces)
		{
			std::cout << " ";
			i++;
		}
		std::cout << data;
	}
}
