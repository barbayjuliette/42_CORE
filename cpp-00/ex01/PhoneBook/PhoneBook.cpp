/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:32:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/11 11:09:38 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <stdlib.h>
#include "PhoneBook.hpp"
#include "../Contact/Contact.hpp"
#include "../phone_book.hpp"

PhoneBook::PhoneBook(void) : total_contacts(0)
{
	// std::cout << "Constructor PhoneBook called" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	// std::cout << "Deconstructor Phonebook called" << std::endl;
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

void	PhoneBook::search(void) const
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
		display_column(contacts[i].get_first_name());
		std::cout << "|";
		display_column(contacts[i].get_last_name());
		std::cout << "|";
		display_column(contacts[i].get_nickname());
		std::cout << std::endl;
		i++;
	}
	choose_index_display(this->total_contacts, this->contacts);
}

const Contact* PhoneBook::get_contacts(void) const
{
	return (this->contacts);
}
