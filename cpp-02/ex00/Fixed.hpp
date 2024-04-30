/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:55:40 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/17 19:12:29 by jbarbay          ###   ########.fr       */
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
		// Default Constructor
		Fixed(void);

		// Copy constructor
		Fixed(const Fixed& num); 

		// Copy assignement operator overload
		Fixed&	operator=(Fixed const& num);
		
		// Destructor
		~Fixed(void);
		
		// Member functions
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
