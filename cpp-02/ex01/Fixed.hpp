/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:34:04 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/20 17:43:29 by jbarbay          ###   ########.fr       */
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
		friend std::ostream& operator<<(std::ostream& os, const Fixed& num);
		Fixed(void); // Constructor
		Fixed(const int num); // Constructor 2
		Fixed(const float num); // Constructor 3
		~Fixed(void); // Destructor
		Fixed(const Fixed& num); // Copy constructor
		void	operator=(Fixed const& num); // Copy assignement operator overload
		int		getRawBits( void ) const;
		int		setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif

// To get cout to accept a Fixed object after the insertion 
// operator, overload the insertion operator to recognize 
// an ostream object on the left and a Fixed on the right. 
// The overloaded << operator function must then be declared 
// as a friend of class Fixed so it can access the private 
// data within a Fixed object.