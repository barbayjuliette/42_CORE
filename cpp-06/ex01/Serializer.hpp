/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:48:51 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/31 17:49:29 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer( Serializer const & src );
		~Serializer();

		Serializer &		operator=( Serializer const & rhs );

	public:
		static	uintptr_t serialize(Data* ptr);
		static	Data* deserialize(uintptr_t raw);
};

#endif