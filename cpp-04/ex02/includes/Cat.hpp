/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 18:12:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 16:46:30 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
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