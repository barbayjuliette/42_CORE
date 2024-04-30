/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:31:19 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/21 16:40:33 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fract = 8;

Fixed::Fixed(void): _fixed(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num): _fixed(num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << _fract;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(num * (1  << _fract));
}

Fixed::~Fixed(void)
{
	// std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixed) / (1  << _fract));
}

int Fixed::toInt( void ) const
{
	return (this->_fixed >> _fract);
}

Fixed::Fixed(const Fixed& num)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

Fixed&	Fixed::operator=(Fixed const& num)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = num._fixed;
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed);
}
int	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
	return (this->_fixed);
}

// Comparison operators

bool	Fixed::operator>(Fixed const& num)
{
	return (this->toFloat() > num.toFloat());
}

bool	Fixed::operator<(Fixed const& num)
{
	return (this->toFloat() < num.toFloat());
}

bool	Fixed::operator>=(Fixed const& num)
{
	return (this->toFloat() >= num.toFloat());
}

bool	Fixed::operator<=(Fixed const& num)
{
	return (this->toFloat() <= num.toFloat());
}

bool	Fixed::operator==(Fixed const& num)
{
	return (this->toFloat() == num.toFloat());
}

bool	Fixed::operator!=(Fixed const& num)
{
	return (this->toFloat() != num.toFloat());
}

// Arithmetic operations

Fixed	Fixed::operator+(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed + num._fixed);
	return (nb);
}

Fixed	Fixed::operator-(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed - num._fixed);
	return (nb);
}

Fixed	Fixed::operator*(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed * num._fixed);
	return (nb);
}

Fixed	Fixed::operator/(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed / num._fixed);
	return (nb);
}

// Decrement / Increment

// Prefix --i

Fixed&	Fixed::operator++(void)
{
	++this->_fixed;
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	--this->_fixed;
	return (*this);
}

// Postfix i++

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	++this->_fixed;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	--this->_fixed;
	return (temp);
}

// Min
Fixed&	Fixed::min(Fixed& one, Fixed& two)
{
	if (one < two)
		return one;
	else
		return two;
}

Fixed const&	Fixed::min(Fixed const& one, Fixed const& two)
{
	if (one.toFloat() < two.toFloat())
		return (one);
	else
		return (two);
}

// Max
Fixed&	Fixed::max(Fixed& one, Fixed& two)
{
	if (one > two)
		return one;
	else
		return two;
}

Fixed const&	Fixed::max(Fixed const& one, Fixed const& two)
{
	if (one.toFloat() > two.toFloat())
		return one;
	else
		return two;
}

std::ostream& operator<<(std::ostream& os, const Fixed &num)
{
	os << num.toFloat();
	return (os);
}


// In the context of fixed-point arithmetic, ε typically represents the smallest increment
// that can be represented by the fixed-point format. It's often referred to as the "epsilon"
// value or the "machine epsilon."

// The inequality 1 + ε > 1 means that when you add the smallest possible increment ε to 1,
// the result should be greater than 1. This condition ensures that the fixed-point representation
// can accurately represent values around 1 without losing precision.

// In other words, ε represents the smallest positive value that can be added to 1 without changing
// the result when rounded to the nearest representable value.
// For example, if you have 8 fractional bits in your fixed-point representation, the smallest
// possible ε would be 1/256, because with 8 bits, you can represent values down to 1/256. Therefore,
// adding 1/256 to 1 should result in a value greater than 1, satisfying the condition 1 + ε > 1.

// In summary, ensuring that 1 + ε > 1 guarantees that the fixed-point representation accurately
// represents values close to 1 without losing precision
