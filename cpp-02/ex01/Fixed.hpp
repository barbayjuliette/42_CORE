/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:34:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/19 16:46:16 by jbarbay          ###   ########.fr       */
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
		Fixed(void); // Constructor
		Fixed(const int num); // Constructor 2
		Fixed(const float num); // Constructor 3
		~Fixed(void); // Destructor
		Fixed(const Fixed& num); // Copy constructor
		void	operator=(Fixed const& num); // Copy assignement operator overload
		void	operator<<(Fixed const& num);
		int		getRawBits( void ) const;
		int		setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif
