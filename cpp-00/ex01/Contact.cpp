/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:26:46 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/15 15:57:28 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(std::string p1, std::string p2, std::string p3, std::string p4, std::string p5)
 : first_name(p1), last_name(p2), nickname(p3), phone_number(p4), darkest_secret(p5)
{
	// std::cout << "Constructor called" << std::endl;
	// std::cout << "First name: " << this->first_name << std::endl;
	// std::cout << "Last name: " << this->last_name << std::endl;
	// std::cout << "Nickname: " << this->nickname << std::endl;
	// std::cout << "Phone number: " << this->phone_number << std::endl;
	// std::cout << "Darkest secret: " << this->darkest_secret << std::endl;
}

Contact::Contact(void)
{
	// std::cout << "Default constructor called" << std::endl;
}

Contact::~Contact(void)
{
	// std::cout << "Deconstructor called" << std::endl;
}

std::string	add_data_contact(std::string prompt)
{
	std::string	data;

	std::cout << prompt;
	std::getline(std::cin, data);
	return data;
}

Contact	Contact::create_contact()
{
	std::cout << "Please enter the information for your new contact\n";
	std::string first = add_data_contact("First name: ");
	std::string last = add_data_contact("Last name: ");
	std::string nickname = add_data_contact("Nickname: ");
	std::string phone = add_data_contact("Phone number: ");
	std::string secret = add_data_contact("Darkest secret: ");
	Contact my_contact(first, last, nickname, phone, secret);

	return (my_contact);
}
