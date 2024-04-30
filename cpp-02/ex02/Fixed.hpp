/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:49:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/21 16:42:40 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int	_fixed;
		static const int	_fract;
	public:

		Fixed(void);
		Fixed(const int num);
		Fixed(const float num);

		~Fixed(void);
		Fixed(const Fixed& num);

		int		getRawBits( void ) const;
		int		setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		Fixed&	operator=(Fixed const& num);
		bool	operator>(Fixed const& num);
		bool	operator<(Fixed const& num);
		bool	operator>=(Fixed const& num);
		bool	operator<=(Fixed const& num);
		bool	operator==(Fixed const& num);
		bool	operator!=(Fixed const& num);

		Fixed	operator+(Fixed const& num);
		Fixed	operator-(Fixed const& num);
		Fixed	operator*(Fixed const& num);
		Fixed	operator/(Fixed const& num);

		Fixed&	operator++(void);
		Fixed&	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&	min(Fixed& one, Fixed& two);
		static Fixed const&	min(Fixed const& one, Fixed const& two);
		static Fixed&	max(Fixed& one, Fixed& two);
		static Fixed const&	max(Fixed const& one, Fixed const& two);
};

std::ostream& operator<<(std::ostream& os, const Fixed &num);

#endif
