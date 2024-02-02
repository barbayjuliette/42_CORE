/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:32:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/02 18:37:02 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <limits>
#include "PhoneBook.hpp"
#include "Contact.hpp"
using namespace std;

PhoneBook::PhoneBook(void) : total_contacts(0)
{
	// cout << "Constructor PhoneBook called" << endl;
}

PhoneBook::~PhoneBook(void)
{
	// cout << "Deconstructor Phonebook called" << endl;
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

void	display_column(string data)
{
	int	len;
	int	i = 0;

	len = data.length();
	while (i < 10)
	{
		if (i == 9 && len > 10)
			cout << ".";
		else if (i < len)
			cout << data[i];
		else
			cout << " ";
		i++;
	}
}

void	display_contact(int total_contacts, Contact contacts[])
{
	int	i;

	cout << "Enter the index of the contact you want to display\n";
	cin >> i;
	while (i < 0 || i >= total_contacts || cin.fail())
	{
		cout << "Please enter a valid index number\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> i;
	}
	cout << endl << "First name: " << contacts[i].first_name << endl;
	cout << "Last name: " << contacts[i].last_name << endl;
	cout << "Nickname: " << contacts[i].nickname << endl;
	cout << "Phone number: " << contacts[i].phone_number << endl;
	cout << "Darkest secret: " << contacts[i].darkest_secret << endl;
}

void	PhoneBook::search(void)
{
	int	i = 0;

	if (this->total_contacts == 0)
	{
		cout << "You have no contacts in your phone book!\n";
		return ;
	}
	cout << "Your phone book: \n";
	while (i < this->total_contacts)
	{
		cout << i << "         ";
		cout << "|";
		display_column(this->contacts[i].first_name);
		cout << "|";
		display_column(this->contacts[i].last_name);
		cout << "|";
		display_column(this->contacts[i].nickname);
		cout << endl;
		i++;
	}
	display_contact(this->total_contacts, this->contacts);
}