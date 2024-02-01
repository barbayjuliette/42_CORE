/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:28:58 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/01 17:49:25 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using namespace std;
#include "Contact.hpp"

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
	int	i = 1;

	cout << "Welcome to your Phonebook\n";
	while (i)
	{
		cout << "What do you want to do?\n";
		cin >> input;
		if (input == "ADD")
		{
			cout << "Please enter the information for your new contact\n";
			string first = add_data_contact("First name: ");
			string last = add_data_contact("Last name: ");
			string nickname = add_data_contact("Nickname: ");
			string phone = add_data_contact("Phone number: ");
			string secret = add_data_contact("Darkest secret: ");
			Contact contact(first, last, nickname, phone, secret);
		}
		i--;
	}
	
	return 0;
}
