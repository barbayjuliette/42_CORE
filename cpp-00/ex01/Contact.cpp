/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:26:46 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/01 17:51:30 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"
using namespace std;

Contact::Contact(string p1, string p2, string p3, string p4, string p5)
 : first_name(p1), last_name(p2), nickname(p3), phone_number(p4), darkest_secret(p5)
{
	cout << "Constructor called" << endl;
	cout << "First name: " << this->first_name << endl;
	cout << "Last name: " << this->last_name << endl;
	cout << "Nickname: " << this->nickname << endl;
	cout << "Phone number: " << this->phone_number << endl;
	cout << "Darkest secret: " << this->darkest_secret << endl;
}

Contact::~Contact(void)
{
	cout << "Deconstructor called" << endl;
}