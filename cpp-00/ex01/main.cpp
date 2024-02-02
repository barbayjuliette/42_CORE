/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:28:58 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/02 17:42:25 by jbarbay          ###   ########.fr       */
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

int main(void)
{
	string input;

	PhoneBook my_phone_book;
	Contact contact1("Juliette", "Barbay", "Juju", "80443702", "Secret");
	Contact contact2("Alejandro", "Zamudio Guajardo", "Alex", "80445737", "Secret");
	my_phone_book.add_contact(contact1);
	my_phone_book.add_contact(contact2);
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
