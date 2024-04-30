/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:34:18 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/21 09:51:34 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fract = 8;

// Constructors
Fixed::Fixed(void): _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num): _fixed(num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << _fract;
	// Transforms 101010 (8)
	// To 10101000000000 (Adds 8 fractional bits)
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(num * (1  << _fract));
	// Multiply num by 256 ((1 << 8) = 100000000). So I take 8 bits that I put into the integer part
	// Then I round up so I get rid of any extra fractional part (over 8 bits)
	// I convert the fractional part of the number to an integer
}

// Copy constructor
Fixed::Fixed(const Fixed& num)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

// Copy assignment operator
Fixed&	Fixed::operator=(Fixed const& num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = num._fixed;
	return (*this);
}
// Destructor
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

// Member functions
int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}

int	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
	return (this->_fixed);
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixed) / (1 << _fract));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed >> _fract);
}

std::ostream& operator<<(std::ostream& os, const Fixed &num)
{
	os << num.toFloat();
	return (os);
}
