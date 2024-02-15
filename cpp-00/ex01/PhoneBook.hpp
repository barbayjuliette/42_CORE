/* ************************************************************************** */
/*                                                    https://profile.intra.42.fr/                        */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:34:27 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/01 15:37:09 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	public:
		Contact contacts[8];
		int	total_contacts;

		PhoneBook(void);
		~PhoneBook(void);
		void add_contact(Contact new_contact);
		void search(void);
};

#endif
