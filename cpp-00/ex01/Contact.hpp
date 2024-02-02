/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:21:32 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/02 16:19:42 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
using namespace std;
#include <string>

class Contact
{
	public:
		string	first_name;
		string	last_name;
		string	nickname;
		string	phone_number;
		string	darkest_secret;

		Contact(string p1, string p2, string p3, string p4, string p5);  // Constructor and deconstructor. Return value is of type void.
		Contact(void);
		~Contact(void);
		void	search(void);
		void	exit(void);
};

#endif