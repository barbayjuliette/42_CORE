/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:12:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 15:21:53 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& src);
		~Cat();

		Cat &		operator=( Cat const & rhs );
		void		makeSound() const;
		Brain*		get_brain() const;
};

#endif