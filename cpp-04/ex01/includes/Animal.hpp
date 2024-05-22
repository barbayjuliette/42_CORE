/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 17:02:44 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal(const Animal& src);
		virtual ~Animal();

		Animal&			operator=( Animal const & rhs );

		virtual void	makeSound() const;
		std::string		getType() const;
		void			setType(std::string type);
};

#endif