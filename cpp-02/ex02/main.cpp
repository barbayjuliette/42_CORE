/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:49:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/21 16:34:43 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	// Fixed c(23);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	// std::cout << (c > a) << std::endl;
	// std::cout << (c > a) << std::endl;

	std::cout << a << std::endl; // 0 OK
	std::cout << ++a << std::endl; // 0.00390625 OK
	std::cout << a << std::endl; // 0.00390625 OK
	std::cout << a++ << std::endl; // 0.00390625 NOK
	std::cout << a << std::endl; // 0.0078125 OK

	std::cout << b << std::endl; // 10.1016 OK

	std::cout << Fixed::max( a, b ) << std::endl; // 10.1016
	return 0;
}
