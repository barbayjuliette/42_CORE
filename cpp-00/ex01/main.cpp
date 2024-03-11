/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:28:58 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/11 11:10:56 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	create_test_cases(PhoneBook *my_phone_book)
{
	Contact contact1("Zero", "Barbay", "Juju", "80443702", "Secret");
	Contact contact2("One", "Zamudio Guajardo", "Alex", "80445737", "Secret");
	Contact contact3("Two", "Barbay", "Juju", "80443702", "Secret");
	Contact contact4("Three", "Zamudio Guajardo", "Alex", "80445737", "Secret");
	Contact contact5("Four", "Barbay", "Juju", "80443702", "Secret");
	Contact contact6("Five", "Zamudio Guajardo", "Alex", "80445737", "Secret");
	Contact contact7("Six", "Barbay", "Juju", "80443702", "Secret");
	Contact contact8("Last", "Zamudio Guajardo", "Alex", "80445737", "Secret");

	my_phone_book->add_contact(contact1);
	my_phone_book->add_contact(contact2);
	my_phone_book->add_contact(contact3);
	my_phone_book->add_contact(contact4);
	my_phone_book->add_contact(contact5);
	my_phone_book->add_contact(contact6);
	my_phone_book->add_contact(contact7);
	my_phone_book->add_contact(contact8);
}

int main(void)
{
	std::string input;

	PhoneBook my_phone_book;
	// create_test_cases(&my_phone_book);
	cout << "Welcome to your Phonebook\n";
	Contact my_contact;
	std::cout << "Welcome to your Phonebook\n";
	while (1)
	{
		std::cout << "\nWhat do you want to do? Options: ADD, SEARCH, EXIT\n";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			my_contact = my_contact.create_contact();
			my_phone_book.add_contact(my_contact);
		}
		else if (input == "SEARCH")
		{
			my_phone_book.search();
		}
		else if (input == "EXIT")
			return 0;
		else
			std::cout << "Wrong option: " << input << "." << std::endl;
	}
	return 0;
}
