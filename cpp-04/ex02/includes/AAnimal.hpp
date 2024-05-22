/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarbay <jbarbay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:37:24 by jbarbay           #+#    #+#             */
/*   Updated: 2024/05/22 16:45:17 by jbarbay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal();
		AAnimal(const AAnimal& src);
		virtual ~AAnimal();

		AAnimal&			operator=( AAnimal const & rhs );

		virtual void	makeSound() const = 0;
		std::string		getType() const;
};

#endif