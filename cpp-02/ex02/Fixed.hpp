/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 18:49:16 by jbarbay           #+#    #+#             */
/*   Updated: 2024/03/20 18:56:36 by jbarbay          ###   ########.fr       */
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
		friend std::ostream& operator<<(std::ostream& os, const Fixed& num);
		void	operator=(Fixed const& num);
		bool	operator>(Fixed const& num);
		int		getRawBits( void ) const;
		int		setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif