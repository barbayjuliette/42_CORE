/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:17:36 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/25 17:17:38 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
# define PHONE_BOOK_HPP

#include <iostream>
#include <cstdlib>
#include "Contact/Contact.hpp"
#include "PhoneBook/PhoneBook.hpp"

std::string	add_data_contact(std::string prompt);
void	push_contacts(Contact contacts[]);
void	choose_index_display(int total_contacts, const Contact contacts[]);
void	display_column(std::string data);

#endif
