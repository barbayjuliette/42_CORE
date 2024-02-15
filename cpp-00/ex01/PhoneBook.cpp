/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:32:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/15 15:43:21 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void) : total_contacts(0)
{
	// std::cout << "Constructor PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "Deconstructor Phonebook called" << std::endl;
}

void	push_contacts(Contact contacts[])
{
	int i = 0;

	while (i < 7)
	{
		contacts[i] = contacts[i + 1];
		i++;
	}
}

void	PhoneBook::add_contact(Contact new_contact)
{
	if (total_contacts == 8)
	{
		push_contacts(this->contacts);
		this->contacts[7] = new_contact;
	}
	else
	{
		this->contacts[this->total_contacts] = new_contact;
		this->total_contacts++;
	}
}

void	display_column(std::string data)
{
	int	len;
	int	i = 0;

	len = data.length();
	while (i < 10)
	{
		if (i == 9 && len > 10)
			std::cout << ".";
		else if (i < len)
			std::cout << data[i];
		else
			std::cout << " ";
		i++;
	}
}

void	display_contact(int total_contacts, Contact contacts[])
{
	int	i;

	std::cout << "Enter the index of the contact you want to display\n";
	std::cin >> i;
	while (i < 0 || i >= total_contacts || std::cin.fail())
	{
		std::cout << "Please enter a valid index number\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> i;
	}
	std::cout << std::endl << "First name: " << contacts[i].first_name << std::endl;
	std::cout << "Last name: " << contacts[i].last_name << std::endl;
	std::cout << "Nickname: " << contacts[i].nickname << std::endl;
	std::cout << "Phone number: " << contacts[i].phone_number << std::endl;
	std::cout << "Darkest secret: " << contacts[i].darkest_secret << std::endl;
}

void	PhoneBook::search(void)
{
	int	i = 0;

	if (this->total_contacts == 0)
	{
		std::cout << "You have no contacts in your phone book!\n";
		return ;
	}
	std::cout << "Your phone book: \n";
	while (i < this->total_contacts)
	{
		std::cout << i << "         ";
		std::cout << "|";
		display_column(this->contacts[i].first_name);
		std::cout << "|";
		display_column(this->contacts[i].last_name);
		std::cout << "|";
		display_column(this->contacts[i].nickname);
		std::cout << std::endl;
		i++;
	}
	display_contact(this->total_contacts, this->contacts);
}
