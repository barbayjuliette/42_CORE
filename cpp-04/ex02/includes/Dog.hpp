/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:12:18 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 16:46:24 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
	private:
		Brain* _brain;
	public:
		Dog();
		Dog(const Dog& src);
		~Dog();

		Dog&		operator=( Dog const & rhs );
		void		makeSound() const;
		Brain*		get_brain() const;

};

#endif