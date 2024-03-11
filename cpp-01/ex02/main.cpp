/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:56:51 by jbarbay           #+#    #+#             */
/*   Updated: 2024/02/20 17:08:49 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*str_ptr = &str;
	std::string& str_ref = str;

	// Address
	std::cout << "Address variable: " << &str << std::endl;
	std::cout << "Address pointer: " << str_ptr << std::endl;
	std::cout << "Address reference: " << &str_ref << std::endl;

	// values
	std::cout << "String variable: " << str << std::endl;
	std::cout << "String pointer: " << *str_ptr << std::endl;
	std::cout << "String reference: " << str_ref << std::endl;

	return 0;
}
