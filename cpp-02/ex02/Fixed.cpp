/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:31:19 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/20 18:59:34 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_fract = 8;

Fixed::Fixed(void): _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num): _fixed(num)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << _fract;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	_fixed = roundf(num * (1  << _fract));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy constructor called" << std::endl;
	*this = num;
}

void	Fixed::operator=(Fixed const& num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = num._fixed;
}

std::ostream& operator<<(std::ostream& os, const Fixed& num) 
{
    os << num.toFloat();
    return (os);
}

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

// Comparison operators

bool	Fixed::operator>(Fixed const& num)
{
	return (this->_fixed > num._fixed);
}

bool	Fixed::operator<(Fixed const& num)
{
	return (this->_fixed < num._fixed);
}

bool	Fixed::operator>=(Fixed const& num)
{
	return (this->_fixed >= num._fixed);
}

bool	Fixed::operator<=(Fixed const& num)
{
	return (this->_fixed <= num._fixed);
}

bool	Fixed::operator==(Fixed const& num)
{
	return (this->_fixed == num._fixed);
}

bool	Fixed::operator!=(Fixed const& num)
{
	return (this->_fixed != num._fixed);
}

// Arithmetic operations

Fixed	Fixed::operator+(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed + num._fixed) >> _fract;
	return (nb);
}

Fixed	Fixed::operator-(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed - num._fixed) >> _fract;
	return (nb);
}

Fixed	Fixed::operator*(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed * num._fixed) >> _fract;
	return (nb);
}

Fixed	Fixed::operator/(Fixed const& num)
{
	Fixed	nb;

	nb._fixed = (this->_fixed / num._fixed) >> _fract;
	return (nb);
}
