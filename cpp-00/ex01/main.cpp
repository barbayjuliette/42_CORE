/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:28:58 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/02 18:43:40 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
using namespace std;
#include "Contact.hpp"
#include "PhoneBook.hpp"

string	add_data_contact(string prompt)
{
	string	data;

	cout << prompt;
	cin >> data;
	return data;
}

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
	string input;

	PhoneBook my_phone_book;
	create_test_cases(&my_phone_book);
	cout << "Welcome to your Phonebook\n";
	while (1)
	{
		cout << "\nWhat do you want to do?\nOptions: ADD, SEARCH, EXIT\n";
		cin >> input;
		if (input == "ADD")
		{
			cout << "Please enter the information for your new contact\n";
			string first = add_data_contact("First name: ");
			string last = add_data_contact("Last name: ");
			string nickname = add_data_contact("Nickname: ");
			string phone = add_data_contact("Phone number: ");
			string secret = add_data_contact("Darkest secret: ");
			Contact my_contact(first, last, nickname, phone, secret);
			my_phone_book.add_contact(my_contact);
		}
		else if (input == "SEARCH")
			my_phone_book.search();
		else if (input == "EXIT")
			return 0;
	}
	
	return 0;
}
